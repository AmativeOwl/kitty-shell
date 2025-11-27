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
[Installation](#installation) <br>
[Usage](#usage)

## Tech Stack <a id="tech-stack"></a>
C, Bash

## Pre-Requisites <a id="pre-reqs"></a>

1. **Install VSCode**  
   Download from [Visual Studio Code](https://code.visualstudio.com/) and install the C/C++ extension.

2. **Install WSL and Ubuntu**
   - Open PowerShell in **Administrator** mode.
   - Inside PowerShell (Admin) run:
     ```
     wsl --install
     ```
   - Alternatively, if the `--install` command is not supported, run:
     ```
     dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
     dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
     wsl --set-default-version 2
     ```
   - Restart your computer.
   - Open the Microsoft Store, search for Ubuntu, and install it.
   - Launch Ubuntu from the Start menu and follow the instructions to set your username and password.

   **Note**: Remember your password because you’ll need it for `sudo` commands!

3. **Install GCC Compiler in WSL Ubuntu**
   - Inside WSL, run:
     ```bash
     sudo apt update
     sudo apt install gcc
     ```
   - Verify installation:
     ```bash
     gcc --version
     ```

## Installation <a id="installation"></a>
Follow these steps to install and run the kitty shell project locally:
#### 1. Connect to WSL in VSCode
- Click on this icon in the bottom-left of the VSCode interface: <img width="40" height="24" alt="image" src="https://github.com/user-attachments/assets/0e255eb3-8acb-4af9-83a0-4cc4569dc669" />
- Select the 'Connect to WSL' option

#### 2. Clone the repository
```bash
git clone https://github.com/AmativeOwl/kitty-shell.git
```

#### 3. Navigate to the project folder 
```bash
cd uv-project
```
