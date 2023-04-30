#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include <utils/hook.hpp>
#include <utils/io.hpp>
#include <utils/string.hpp>
#include <utils/thread.hpp>
#include <utils/compression.hpp>

#include <exception/minidump.hpp>

namespace player
{
    namespace
    {
        utils::hook::detour g_clientdoperframenotifies_hook;

        void G_ClientDoPerFrameNotifies_custom(game::gentity_s* ent)
        {
            game::gclient_s* client; // esi
            unsigned int weapon; // eax
            bool clientIsFiring; // bl

            client = ent->client;
            weapon = client->ps.weapon;
            if (weapon != client->lastWeapon)
            {
                game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, game::BG_WeaponNames[weapon]->szInternalName);
                game::Scr_NotifyNum(game::SCRIPTINSTANCE_SERVER, ent->s.number, 0, game::scr_const->weapon_change, 1);
                weapon = client->ps.weapon;
                client->lastWeapon = weapon;
            }
            if (!client->previouslyChangingWeapon || client->ps.weaponstate == game::WEAPON_RAISING || client->ps.weaponstate == game::WEAPON_RAISING_ALTSWITCH)
            {
                if (client->ps.weaponstate == game::WEAPON_RAISING || client->ps.weaponstate == game::WEAPON_RAISING_ALTSWITCH)
                    client->previouslyChangingWeapon = 1;
            }
            else
            {
                game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, game::BG_WeaponNames[weapon]->szInternalName);
                game::Scr_NotifyNum(game::SCRIPTINSTANCE_SERVER, ent->s.number, 0, game::scr_const->weapon_change_complete, 1);
                client->previouslyChangingWeapon = 0;
            }
            clientIsFiring = client->ps.weaponstate == game::WEAPON_FIRING && client->ps.pm_type < game::PM_LASTSTAND_TRANSITION;
            if (clientIsFiring != client->previouslyFiring)
            {
                if (clientIsFiring)
                    game::Scr_NotifyNum(game::SCRIPTINSTANCE_SERVER, ent->s.number, 0, game::scr_const->begin_firing, 0);
                else
                    game::Scr_NotifyNum(game::SCRIPTINSTANCE_SERVER, ent->s.number, 0, game::scr_const->end_firing, 0);
                client->previouslyFiring = clientIsFiring;
            }
            if ((client->ps.weapFlags & 0x40) != 0)
            {
                if (!client->previouslyUsingNightVision)
                {
                    client->previouslyUsingNightVision = 1;
                    game::Scr_NotifyNum(game::SCRIPTINSTANCE_SERVER, ent->s.number, 0, game::scr_const->night_vision_on, 0);
                }
            }
            else if (client->previouslyUsingNightVision)
            {
                client->previouslyUsingNightVision = 0;
                game::Scr_NotifyNum(game::SCRIPTINSTANCE_SERVER, ent->s.number, 0, game::scr_const->night_vision_off, 0);
            }

            //New addition
            if (game::PM_IsSprinting(&client->ps))
            {
                if (!client->previouslySprinting)
                {
                    client->previouslySprinting = true;
                    std::string sprintBeginNotifyStr("sprint_begin");
                    game::Scr_NotifyNum(game::SCRIPTINSTANCE_SERVER, ent->s.number, 0, game::SL_GetStringOfSize(game::SCRIPTINSTANCE_SERVER, sprintBeginNotifyStr.data(), 0, sprintBeginNotifyStr.length()), 0);
                }
            }
            else if (client->previouslySprinting)
            {
                client->previouslySprinting = false;
                std::string sprintBeginNotifyStr("sprint_end");
                game::Scr_NotifyNum(game::SCRIPTINSTANCE_SERVER, ent->s.number, 0, game::SL_GetStringOfSize(game::SCRIPTINSTANCE_SERVER, sprintBeginNotifyStr.data(), 0, sprintBeginNotifyStr.length()), 0);
            }
        }

        void __declspec(naked) G_ClientDoPerFrameNotifies_stub()
        {
            __asm
            {
                push edi;

                call G_ClientDoPerFrameNotifies_custom;
                add esp, 0x4;
                ret;

            }
        }
    }

    class component final : public component_interface
    {
    public:
        void post_unpack() override
        {
            // test usercall detour!
            g_clientdoperframenotifies_hook.create(game::G_ClientDoPerFrameNotifies(), G_ClientDoPerFrameNotifies_stub);
        }
    };
}

REGISTER_COMPONENT(player::component)