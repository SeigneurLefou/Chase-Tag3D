# Fps3DCast
## Install and execute
Clone the repo with the following command
```bash
git clone https://github.com/SeigneurLefou/Chase-Tag3D && cd Chase-Tag3D
```
Compile the project with the following command
```bash
make re
```
Now you can execute the server in one terminal
```bash
./bin/server
```

And if you execute the client the server receive all the message
```bash
./bin/client We are multiple arguments
```
## Roadmap
### First step in networking
- [x] Client-server communication
- [ ] List host client and simple client
- [ ] Host connexion system
- [ ] Client-Host request

### Start of the game logic
- [ ] Game logic for movement
- [ ] Multiplayer logic
- [ ] Ray casting graphics
- [ ] Action of the players

### Connect net and game
- [ ] Give input of the player to the host for he calculate
- [ ] Write the rest of the roadmap

## Networking from home
The client request to the server are the following :
GET for pull info like host list
POST for push info
CONNECT to connect to an account

### Gamemode :
- Chase tag
- Catch the flags
- Zone capture
- Dual team
- Battle royal
### Theme of the game :
- Egypt
- Infernum
- Gore
- Catacombs
- Dark fantasy
