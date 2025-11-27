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
   2.1>    Open PowerShell in **Administrator** mode. <br>
   2.2A>   Inside PowerShell (Admin) run: 
          ```wsl --install``` <br>
   2.2B>   Alternatively, if the ```--install``` command is not supported, run: <br>
         ```
         dism.exe /online /enable-feature
         /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
         dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all
         /norestart
         wsl --set-default-version 2
          ``` <br>
   2.3>    To apply the WSL installation above, restart your computer. <br>
   2.4>    After restarting, open the Microsoft store, search for Ubuntu and install it. <br>
   2.5>    Once installed, open Ubuntu from the Start menu. <br>
   2.6>    Follow the in-screen instructions to set your username and password. <br>

   **Note**: It is important that you remember your password as it will be needed to run ```sudo``` commands.
   
3. Install the GCC Compiler in WSL Ubuntu: <br>
   3.1>    Inside WSL, run: <br>
          ```bash
          sudo apt update
          sudo apt install gcc
          ``` <br>
   3.2>    To verify GCC installation, run: <br>
          ```bash
          gcc --version
          ``` <br>
