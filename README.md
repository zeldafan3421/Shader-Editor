# Shader Viewer
A simple shader viewer for opengl glsl shaders.

## Supported Platforms
* Windows
* Linux
* MacOS

## Controls 
F1: toggle window decorations.
1 : Show cube.
2 : Show Cone.
3 : Show Sphere.
4 : Custom model (added by dropping file into window).

## Features
1. Auto reloads shaders when the files are modified.
2. Import Custom models and textures by dropping them into the window.

## Limitations 
1. Shader files must me in the project directory next to the exe.
2. Limited support for multipy modelled meshes.
3. Custom attributes and uniforms not yet supported.
4. Locked internal rendering resolution. 

## Ideas 
I plan on eventually expanding this to be an entire editor but I want to have the viewing functioning well first.

## Credits
  Built using Raylib and Raylib quickstart.
  www.raylib.com and
  https://github.com/raylib-extras/raylib-quickstart

  Uses portable file dialogs for systems prompts.
  https://github.com/samhocevar/portable-file-dialogs
