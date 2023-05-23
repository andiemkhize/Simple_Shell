# simple_shell

A basic simple shell implementation in C

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installion)
- [Usage](#usage)
- [Commands](#commands)

## Introduction

Welcome to **simple_shell**! This project is a basic simple shell implementation written in C, inspired by popular Unix-like shells.The goal of this project is to provide a user-friendly command-line interface that allows users to interact with their operating system.

## Features

- Lightweight
- Minimalistic

## Installation

To use **simple_shell**, follow these steps:

1. Clone the repository: `git clone https://github.com/andiemkhize/simple_shell.git`
2. Navigate to the project directory: `cd simple_shell`
3. Compile the source code `gcc *.c *.h -o hsh`
4. Run the shell: `./hsh`

## Usage

Once you have installed **simple shell**, you can use it just like any other shell. Enter commands at the prompt and press Enter to execute them. Here are a few examples to get you started:

```shell
$ ls
$ env
$ echo "Hello, World!"
$ exit
```

## Commands

Please note that simple_shell supports a subset of common shell commands. Here are the commands currently supported:

- `ls`: List files and directories
- `echo`: Display text or variables
- `env`: Show environment variables
- `exit`: Terminate the shell

Please be aware that commands like `cd` for changing directories are not supported in this version of the shell. Keep in mind the limitations when using the shell for navigation purposes.
