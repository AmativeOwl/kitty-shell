# Kitty Shell

The _kitty shell_ is a simple shell interface that runs both Linux and custom kitty-themed commands! 

This project reflects three core aspects of me:
1. My unwavering love for my friendly feline friends!
2. My desire to apply the C programming language in a new manner (aside from algorithms)
3. My interest in operating systems (cultivated by my university's course offerings)

Indeed, this was a basic, light-hearted extension beyond my course that not only helped me navigate the intricacies of C, but also deepened my appreciation for the language. As such, please treat this project as more of a fun endeavour (if anything).

## Table of Contents
[Tech Stack](#tech-stack) <br>
[Pre-Requisites](#pre-reqs) <br>

## Tech Stack <a id="tech-stack"></a>
C, Bash

## Pre-Requisites <a id="pre-reqs"></a>
1. Install VSCode: Download from [Visual Studio Code](https://code.visualstudio.com/) and install the C/C++ extension.
2. Install WSL and Ubuntu: <br>
   Open PowerShell in **Administrator** mode.
   Inside PowerShell (Admin) run:
   ```wsl --install```
   
   Alternatively, if the ```--install``` command is not supported, run:
   ```
   dism.exe /online /enable-feature
   /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
   dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all
   /norestart
   wsl --set-default-version 2
    ```
   <br> 
   To apply the WSL installation above, restart your computer. <br>
   After restarting, open the Microsoft store, search for Ubuntu and install it. <br>
   Once installed, open Ubuntu from the Start menu. <br>
   Follow the in-screen instructions to set your username and password. <br>

   **Note**: It is important that you remember your password as it will be needed to run ```sudo``` commands.
   
4. Install the GCC Compiler in WSL Ubuntu: <br>
   Inside WSL, run:
   ```bash
   sudo apt update
   sudo apt install gcc
   ```

   To verify GCC installation, run:
   ```bash
   gcc --version
   ```
