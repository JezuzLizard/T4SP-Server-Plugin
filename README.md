# T4SP-Server-Plugin
A plugin that has code that hopefully compiles and the game will load it to do things. Stability not guaranteed.

Requires Git (https://git-scm.com/), Premake5 (https://premake.github.io/), and MSVC 2022 (https://visualstudio.microsoft.com/vs/features/cplusplus/) to build.

# Features
## FileIO
This plugin provides FileIO interface to GSC for reading and writing files, this is exact to [CoD4x's](https://github.com/callofduty4x/CoD4x_Server/blob/master/scriptdocumentation/script_functions_reference.md#file-operations) interface.

However, all reads and writes will take place strictly and only in the `scriptdata` folder.

All files will be closed upon GSC restart (map_restart or fast_restart or missionfailed, etc).

* `<int> FS_TestFile(<filename string>)` Returns `true` if the file exists, `false` otherwise.
  ```gsc
  if (FS_TestFile("test.txt"))
  {
    PrintConsole("Found test.txt!");
  }
  ```
* `<int> FS_Remove(<filename string>)` Deletes the file, return `true` if successful.
  ```gsc
  if (FS_Remove("test.txt"))
  {
    PrintConsole("test.txt was deleted!");
  }
  ```

# Installation
Move the `t4sp-server-plugin.dll` to `%LOCALAPPDATA%\Plutonium\storage\t4\plugins\`, the plugin will be loaded when you start up a dedicated server for Plutonium T4SP.

# Credits
- momo5502 (https://github.com/momo5502)
- xensik (https://github.com/xensik/gsc-tool)
- fedddddd (https://github.com/fedddddd/t6-gsc-utils)
- VoroN (https://github.com/voron00/CoD2rev_Server)
- CoD4x team (https://github.com/callofduty4x/CoD4x_Server)
- id Software (https://github.com/id-Software/Quake-III-Arena)
- Treyarch
- Infinity Ward
- Activision
