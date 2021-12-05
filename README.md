# Fax

Collaborative communication application

## Description

Fax is a project which allows to communicate in networks via a small shell.

There are two binaries

- **fax_server**
- **fax_client**

**fax_server** is the server.

When **fax_server** users can launch **fax_client** to start texting with others.

## Language

- **C**

## Os supported

- **Linux**

## Dependecies

### Linux

Minimum required

- Make 4.3
- gcc 10.3.0

## How to build

### Linux

At the root of the repository, go to **linux** directory

tape

    make re

The two biaries **fax_server** and **fax_client** will be generated in the **linux** derectory

## How to use

### fax_server

    USAGE: ./fax_server port

	    port is the port number on which the server socket listens.

Since **fax_server** is launched on a port users can now use **fax_cli** to text with others ;)

### fax_cli

    USAGE: ./fax_cli ip port
	    ip is the server ip address on which the server is launched
	    port is the port number on which the server is launched

**fax_cli** is a shell prompt which allow you to text, chat and more with others.

When **fax_cli** is launched you can tape

    /help

To see availables commands

Hope you will enjoy my program ;)
