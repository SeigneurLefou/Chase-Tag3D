# Ellipsis's project (Multiplayer)

An Fast FPS game with players against the mob. It's the starting of the project.

## Overview

The goal of this project is to create a robust foundation for 2D multiplayer games. It features a **Server-Authoritative** model where the server handles all game logic (movement, collisions) and broadcasts the state to all connected clients.

### Key Technical Features:
* **Dual-Threaded Server:** A dedicated network thread manages client connections (`select()` multiplexing) while the main thread handles real-time rendering.
* **SDL3 Integration:** Utilizes the latest SDL3 API with OpenGL for hardware-accelerated rendering and efficient event handling.
* **Clean OOP Architecture:** Decoupled classes for `Game`, `Player`, `Map`, and `Server` to ensure maintainability.

## Roadmap
Phase 1: Networking Foundations

- [x] Basic Client-Server communication (TCP Sockets).
- [x] Multi-client handling via select() on the server.
- [ ] Implement a handshake system for host connection.
- [ ] Unique ID assignment for each connected client.

Phase 2: Game Logic & Rendering

- [x] Basic 2D square movement with SDL3.
- [ ] In Progress: Integrating 8-way movement normalization.
- [ ] Synchronized Multiplayer logic (Server calculates, Client displays).
- [ ] Transition from 2D squares to Rasterizer.

Phase 3: Network Synchronization
- [ ] Input streaming: Send raw scancodes from Client to Host.
- [ ] State broadcasting: Host sends updated coordinates to all Clients.
- [ ] Latency compensation (Client-side interpolation).

## Installation & Build

### Prerequisites
* **C++ Compiler** (G++)
* **SDL3 Library**
* **CMake**

### Compilation
To build both the **Client** and **Server**, run:
```bash
make all
```

### Running the Project
1. **Start the Server:**
   ```bash
   ./server
   ```
2. **Connect a Client:**
   ```bash
   ./client 127.0.0.1
   ```

## Architecture

### Server Logic
The server operates with a non-blocking `select()` loop to manage multiple file descriptors (clients). It updates the `key_table` for each player based on received network packets and calculates the new world state 60 times per second.

### Client Logic
The client is "thin": it captures inputs via `SDL_PollEvent`, sends them to the server, and renders the entities based on the positions received from the network.

## License
This project is open-source and available under the **MIT License**.
