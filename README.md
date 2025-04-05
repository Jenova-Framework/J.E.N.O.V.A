
# Projekt J.E.N.O.V.A

![JENOVA-Screenshot](https://github.com/user-attachments/assets/f17e2947-622d-47c2-9d2f-de10137a3279)

<h3 align="center">
 <a href="https://jenova-framework.github.io/docs/">Documentation</a> • <a href="https://youtu.be/r01HLjdXV6o">Video Log I</a> • <a href="https://youtu.be/QnX8RZW9Jiw">Video Log II</a> • <a href="https://youtu.be/yDTRpFKqWwo">Features</a> • <a href="https://github.com/Jenova-Framework/Jenova-Runtime">Source Code</a>
</h3>

## 🪶 What is it?
**Projekt J.E.N.O.V.A** is a comprehensive series of extension libraries for the Godot 4 Game Engine that brings fully-featured C++ scripting directly into the Godot Editor. It allows the use of modern C++20 standards within the Godot Engine, similar to GDScript. 

By using Jenova Framework you can easily program your entire game or application in C/C++ without any issues. You can also integrate OpenCV, CUDA, Vulkan, OpenMP and any other modern C++ features seamlessly, All supported by the powerful backend.

### Structure of Projekt J.E.N.O.V.A
- **Jenova Framework**: The framework contains Jenova Runtime and JenovaSDK.
- **Jenova Runtime (Core)**: The heart of the framework, It includes the Jenova Interpreter, Jenova Compiler Interface, Jenova Packer, etc.
- **JenovaSDK**: An optional component of Jenova Runtime, providing helpers and APIs for hot-reloading, global allocation/access, etc.

## 🛠️ Current Features
- Super Lightweight (5MB)
- User-Friendly and Easy to Use
- Very Fast & Reliable
- Multi-Threaded Compilation & Source Caching
- Debug Information Support
- Managed Safe Execution (MSE)
- Built-in Package Manager (Compilers, SDKs, Tools, Plugins etc.)
- C++ Scripts can be used exactly like GDScripts
- Supports Script Templates (Pre-Defined/User-Defined)
- Supports Built-in Script Mode (Embedded)
- Supports C++ Tool Script Mode (In-Editor Execution)
- Supports Exporting Properties, Resources and References from C++ Scripts
- Supports Engine Method/Property Queries (Animation Editor, Binding etc.)
- Supports Custom Class Name & Custom Class Icon for C++ Scripts
- Supports Custom Documentation for C++ Scripts
- Full Support for MSVC, LLVM, MinGW and GCC/Clang
- Multiple Interpreter Backends (NitroJIT, Meteora, A.K.I.R.A etc.)
- Next-Gen Hot-Reloading Both at Runtime & Editor
- Real-Time GDExtension Development
- Operating System Emulation (Unix/WinNT)
- Visual Studio Side-by-Side Deep-Integration
- Visual Studio Exporter & Build System (2017-2022)
- Visual Studio Code Integration (Windows/Linux)
- Auto Detection of Installed Visual Studios
- Supports External Libraries and .NET Invoke
- Watchdog System (Reload-On-Build)
- Built-in Terminal Logging System (Customizable)
- Asset Monitor System API (File/Directory Tracking)
- On-Demand Reload Per Script Change
- Lambda Signal Callbacks
- Advanced Menu Options
- Supports Additional/External Headers & Libraries
- Build And Run Mode (Build Before Play/Play After Build)
- Code Compression/Encryption (External/Built-in)
- Direct GetNode & GetTree API
- User Defined Preprocessor Definitions
- Supports In-Editor C++ Headers
- Module Boot/Shutdown Events
- Capable of Invoking C# (GodotSharp) and GDScript Directly
- Compatible with Mono Builds
- Supports C++ Headers Directly Inside Editor
- Supports Scene Node Referencing
- Supports Source Control using Git
- Supports Blazium and Redot Forks
- And Much More!

## 📋 Source Code
Jenova Source Code is now available on [GitHub](https://github.com/Jenova-Framework/Jenova-Runtime) for everyone under MIT license.

## 👻 Why Called Jenova?
I've received some amusing comments about the project name, so here's the backstory. Although I'm a huge FF7 fan, the name isn’t directly linked to Final Fantasy. Jenova is derived from 'Jehovah,' meaning 'New God.' I chose this name because Godot translates to 'Small God.' Therefore, in this context, Jenova signifies a new god emerging from a small god. Additionally, it means 'Well-Born'

Now, why Jenova and J.E.N.O.V.A? The answer is straightforward. Name formatting like this was popular in the 2000s, similar to F.E.A.R. or A.K.I.R.A. It doesn't reference anything specific. However, it's worth noting that Projekt J.E.N.O.V.A refers to the entire toolchain, which includes the Framework, Runtime, Emulator, etc.

## 🛠️ GDExtension vs Jenova Framework
Jenova Framework is not only a toolset to ease the development of GDExtension in Godot, It implements a fully-featured C++ script backend and adds deep integration to the engine script interface just like GDScript, C#, and Python.

Jenova Runtime contains an interpreter and C++ Script Instance implementation. Jenova Framework itself comes with C++ Script Object and C++ Language implementations. Everything works together to bring the actual scripting experience using the C++ language.

## 📃 Getting Started
To get started with the Jenova Framework you can visit the official [Documentation](https://jenova-framework.github.io/docs/pages/Getting-Started). While the Jenova Framework is fairly easy to use its extensive features can be a bit overwhelming. 
To help you navigate we've prepared a very detailed guide that covers every detail and component of the framework. 
Additionally, we regularly publish video tutorials to provide further assistance.

Projekt J.E.N.O.V.A also has an offical Discord Server:

<a href="https://discord.gg/p7zAf6aBPz" title="Join J.E.N.O.V.A Official Discord Server"><img src="https://assets-global.website-files.com/6257adef93867e50d84d30e2/636e0b5061df29d55a92d945_full_logo_blurple_RGB.svg" alt="Discord" height="40" /></a>

> [!IMPORTANT]  
> Jenova Supports Godot 4.2+, Windows 7 to 11 x64 and Linux x64, Mac support is not planned for now.
> Jenova provides MSVC, Clang-cl, MinGW, LLVM Clang and GCC Support, However you can use Visual Studio on Windows directly without [Jenova MSVC Compiler Package](https://github.com/Jenova-Framework/Jenova-Packages/releases/tag/jenova-msvc-compiler-pkg-14.41.34120).
>
> If you need C++ Scripting with support Mac you can use [Godot Sandbox](https://github.com/libriscv/godot-sandbox).

> [!NOTE]  
> Current builds do not include the Virtual Machine and Emulator. While the code for these features is present, they are disabled because they are still heavily under development.

> [!CAUTION]
> Current builds are in the Alpha stage, Backup your project files! You may end up with data loss! Despite the current build being stable, having backups is always recommended.

---
***Jenova is a Free software.***

Developed with 💙 and 🩸By Hamid.Memar
