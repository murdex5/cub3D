# 🎮 Cub3D

A **3D maze game engine** built from scratch in C using raycasting techniques, inspired by the classic Wolfenstein 3D. This project is part of the 42 school curriculum and demonstrates advanced graphics programming with the MiniLibX library.

![Language: C](https://img.shields.io/badge/Language-C-blue.svg)
![School: 42](https://img.shields.io/badge/School-42-black.svg)

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Map Configuration](#map-configuration)
- [Controls](#controls)
- [Technical Details](#technical-details)
- [Contributing](#contributing)

## 🎯 Overview

Cub3D creates a realistic 3D representation of a maze from a first-person perspective using the **raycasting** algorithm. The project handles:

- Real-time 3D rendering
- Texture mapping on walls
- Player movement and rotation
- Collision detection
- Map parsing and validation

## ✨ Features

- **Ray-casting engine**: Efficient 3D rendering from a 2D map
- **Texture mapping**: Different textures for each cardinal direction (North, South, East, West)
- **Smooth movement**: WASD movement with arrow key rotation
- **Custom maps**: Load your own maze configurations
- **Color customization**: Configure floor and ceiling colors
- **Error handling**: Comprehensive validation and error messages
- **Cross-platform**: Works on Linux systems with X11

## 📁 Project Structure

```
cub3D/
├── main/               # Main program and hook handlers
├── parser/             # Map and configuration parsing
├── render/             # Raycasting and rendering logic
├── movement/           # Player movement and rotation
├── init/               # Initialization functions
├── checks/             # Map validation and checks
├── errors/             # Error handling and messages
├── frees/              # Memory management
├── utils/              # Utility functions
├── textures/           # Wall texture files (.xpm)
├── maps/               # Map configuration files (.cub)
├── libft/              # Custom C library
├── mlx/                # MiniLibX graphics library
├── cub3D.h             # Main header file
├── Makefile            # Build configuration
└── install.sh          # Installation script
```

## 🔧 Prerequisites

- **GCC** compiler
- **Make**
- **Git**
- **X11** development libraries
- **XShm** extension

### Installing Dependencies (Debian/Ubuntu)

```bash
sudo apt-get update
sudo apt-get install gcc make git libx11-dev libxext-dev libbsd-dev
```

## 🚀 Installation

### Option 1: Automated Installation (Recommended)

The repository includes an installation script that handles all dependencies:

```bash
# Clone the repository
git clone https://github.com/murdex5/cub3D.git
cd cub3D

# Make the script executable and run it
chmod +x install.sh
./install.sh
```

### Option 2: Manual Installation

```bash
# Clone the repository
git clone https://github.com/murdex5/cub3D.git
cd cub3D

# Initialize and update submodules (MiniLibX)
git submodule init
git submodule update

# Build the project
make
```

### Cleaning Up

```bash
# Remove object files
make clean

# Remove object files and binary
make fclean

# Rebuild from scratch
make re

# Remove binary using install script
./install.sh -r
```

## 🎮 Usage

Run the program with a map file:

```bash
./cub3D <path_to_map_file>
```

### Example

```bash
./cub3D maps/map.cub
```

## 🗺️ Map Configuration

Map files use the `.cub` extension and follow this format:

### Map File Structure

```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Configuration Elements

| Element | Description | Format |
|---------|-------------|--------|
| `NO` | North wall texture | Path to `.xpm` file |
| `SO` | South wall texture | Path to `.xpm` file |
| `WE` | West wall texture | Path to `.xpm` file |
| `EA` | East wall texture | Path to `.xpm` file |
| `F` | Floor color | RGB format: `R,G,B` (0-255) |
| `C` | Ceiling color | RGB format: `R,G,B` (0-255) |

### Map Characters

| Character | Meaning |
|-----------|---------|
| `0` | Empty space (walkable) |
| `1` | Wall |
| `N` | Player starting position (facing North) |
| `S` | Player starting position (facing South) |
| `E` | Player starting position (facing East) |
| `W` | Player starting position (facing West) |
| ` ` (space) | Void (outside map boundaries) |

### Map Rules

1. Map must be surrounded by walls (`1`)
2. Must contain exactly one player spawn point (`N`, `S`, `E`, or `W`)
3. All lines must be closed (no gaps in walls)
4. Invalid characters will cause an error

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` (Left Arrow) | Rotate camera left |
| `→` (Right Arrow) | Rotate camera right |
| `ESC` | Exit game |

## 🔬 Technical Details

### Constants

```c
#define WIN_HEIGHT 720      // Window height in pixels
#define WIN_WIDTH 960       // Window width in pixels
#define ROTSPEED 0.015      // Rotation speed
#define MOVSPEED 0.015      // Movement speed
```

### Core Components

#### 1. **Parser**
- Reads and validates `.cub` map files
- Parses textures, colors, and map layout
- Validates map integrity (closed walls, single player, etc.)

#### 2. **Raycasting Engine**
- Implements DDA (Digital Differential Analysis) algorithm
- Calculates ray-wall intersections
- Determines wall heights based on distance

#### 3. **Renderer**
- Draws textured walls
- Applies perspective correction
- Renders floor and ceiling colors

#### 4. **Movement System**
- Handles player input
- Implements collision detection
- Updates player position and direction

### Performance Considerations

- **Frame-by-frame rendering**: Uses `mlx_loop_hook` for continuous rendering
- **Efficient raycasting**: Only casts rays for visible screen columns
- **Texture optimization**: Pre-loads textures into memory
- **Collision detection**: Checks map boundaries before movement

## 🛠️ Development

### Compilation Flags

```makefile
FLAGS = -Wall -Wextra -Werror
```

### Adding Custom Textures

1. Create or obtain `.xpm` texture files
2. Place them in the `textures/` directory
3. Update your `.cub` map file with the new texture paths

### Creating Custom Maps

1. Create a new `.cub` file in the `maps/` directory
2. Follow the map configuration format
3. Ensure the map is properly closed with walls
4. Test with `./cub3D maps/your_map.cub`

## 🐛 Troubleshooting

### Common Issues

**Error: "Wrong file type! expected type .cub"**
- Ensure your map file has the `.cub` extension

**Error: "No player found"**
- Add exactly one player spawn point (`N`, `S`, `E`, or `W`) in your map

**Error: "Invalid color"**
- Check floor (`F`) and ceiling (`C`) RGB values are in format `R,G,B` with values 0-255

**Segmentation fault**
- Verify map is properly closed with walls
- Check for missing texture files

## 📝 License

This project is part of the 42 school curriculum. Feel free to use it for educational purposes.

## 👨‍💻 Author

**murdex5** - [GitHub Profile](https://github.com/murdex5)

## 🙏 Acknowledgments

- 42 School for the project specifications
- The MiniLibX graphics library developers
- Wolfenstein 3D for the inspiration

---

*Made with ☕ at 42 School*