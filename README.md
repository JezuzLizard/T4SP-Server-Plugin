# T4SP-Server-Plugin
A plugin that has code that hopefully compiles and the game will load it to do things. Stability not guaranteed.

Requires Git (https://git-scm.com/), Premake5 (https://premake.github.io/), and MSVC 2022 (https://visualstudio.microsoft.com/vs/features/cplusplus/) to build.

# Features

Detours and reimplements the entire GSC VM + compiler.

Adds custom GSC functions.

## FileIO
This plugin provides FileIO interface to GSC for reading and writing files, this is exact to [CoD4x's](https://github.com/callofduty4x/CoD4x_Server/blob/master/scriptdocumentation/script_functions_reference.md#file-operations) interface.

However, all reads and writes will take place strictly and only in the `scriptdata` folder, no up directory traversal allowed.

All files will be closed upon GSC restart (map_restart or fast_restart or missionfailed, etc), only a maximum of 10 files may be opened at once.

* `<bool> FS_TestFile(<filename string>)` Returns `true` if the file exists, `false` otherwise.
* `<bool> FS_Remove(<filename string>)` Deletes the file, return `true` if successful, `false` otherwise.
  ```gsc
  // test to see if "scriptdata/test.txt" file exists
  if (FS_TestFile("test.txt")) // not a typo, all file io will take place inside the "scriptdata" folder
  {
    PrintConsole("Found test.txt!");

    // delete it!
    if (FS_Remove("test.txt"))
    {
      PrintConsole("test.txt was deleted!");
    }
  }
  ```

* `FS_FCloseAll()` Closes every full file.
  ```gsc
  // open some files

  FS_FCloseAll(); // close them all
  ```

* `<int> FS_FOpen(<filename string>, <mode string>)` Tries to open the file, mode must be one of `read`, `write` (clears the file), `append` (appends to the file), returns the filehandle. Will return `0` if failed to open.
* `FS_FClose(<filehandle int>)` Closes the file pointed by the filehandle given, which was returned from `FS_FOpen`.
  ```gsc
  // opens "scriptdata/test.txt", all io will take place inside the "scriptdata" folder
  f = FS_FOpen("test.txt", "read"); // can be "read" "write", or "append"

  if (!f)
  {
    PrintConsole("test.txt failed to be opened for reading!");
  }
  else
  {
    // do stuff with the file

    FS_FClose(f); // make sure to close it
  }

  ```

* `<string> FS_ReadLine(<filehandle int>)` Reads a line from the file pointed by the filehandle, removes the newline char. Returns `undefined` when nothing is left to read. Will not read more than 65536 characters at once. Filehandle must be opened for reading.
* `<string> FS_Read(<filehandle int>, <bytes int>(optional))` Reads number of bytes from the file. If bytes is `undefined`, reads the entire file. No more than 65536 characters will be read at once. Returns `undefined` if there are nothing left to read.
  ```gsc
  // open the file for reading

  line = FS_ReadLine(f);
  while (isDefined(line))
  {
    // do something with line

    line = FS_ReadLine(f);
  }

  // entire file is read

  // close the file
  ```

* `<bool> FS_WriteLine(<filehandle int>, <contents string>)` Writes to the file pointed by the filehandle. Appends a newline character. Returns `true` if successful, `false` otherwise. Filehandle must be opened for writing.
* `<bool> FS_Write(<filehandle int>, <contents string>)` Same as above, does not add a newline character.
  ```gsc
  // open the file for writing

  FS_WriteLine(f, "writing some text with newline added");

  FS_Write(f, "no newline here");
  FS_Write(f, "i manually add a newline\n");

  // close the file
  ```

* `<array of strings> FS_ListFiles(<folder string>)` Returns a list of files inside of the folder given.
  ```gsc
  files = FS_ListFiles("testfolder/");

  for (i = 0; i < files.size; i++)
  {
    file = files[i]; // will be "testfolder/<filename>"

    // do something with the filename
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
