# 🎮 Cub3D

<div align="center">
  <img height="200" src="https://github.com/murdex5/cub3D/blob/main/ex_imgs/Screenshot%20from%202026-02-09%2013-58-00.png?raw=true"/>
</div>
<div align="center">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Make](https://img.shields.io/badge/Make-C1302E?style=for-the-badge&logo=gnu&logoColor=white)
![42 School](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)

*A simple 3D maze game engine built with ray-casting*

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Map Format](#-map-format) • [Controls](#-controls)

</div>

---

## 📖 About

**Cub3D** is a 42 school project inspired by the legendary **Wolfenstein 3D** game. This project implements a 3D maze game engine using **ray-casting** techniques with the **MiniLibX** graphics library. Navigate through custom maze environments rendered in real-time with textured walls, floor, and ceiling colors.

#### Note: As for the new curriculem make sure to create and add your README file to the project.

## ✨ Features

- 🎯 **Ray-casting rendering engine** - Real-time 3D visualization from a 2D map
- 🖼️ **Textured walls** - Different textures for each cardinal direction (North, South, East, West)
- 🎨 **Customizable colors** - Configure floor and ceiling colors in RGB
- 🗺️ **Custom map support** - Create and load your own maze layouts
- ⌨️ **Smooth controls** - WASD movement and arrow key rotation
- 🔍 **Map validation** - Robust parsing with detailed error messages
- 🚪 **Collision detection** - Prevents walking through walls
- 📐 **Variable map dimensions** - Support for different maze sizes and shapes

## 🛠️ Installation

### Prerequisites

- **GCC** compiler
- **Make**
- **X11** libraries (for MiniLibX)
- **Git**

### Quick Install

```bash
curl -sSL https://raw.githubusercontent.com/murdex5/cub3D/refs/heads/main/git.install.sh | bash
```
#### OR

Clone the repository and run the automated installation script:

```bash
git clone https://github.com/murdex5/cub3D.git
cd cub3D
bash install.sh
```

The script will:
1. Check for required dependencies
2. Clone and configure MiniLibX
3. Compile the project
4. Display usage instructions

### Manual Installation

If you prefer manual installation:

```bash
# Install the required dependencies
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

# Clone the repository
git clone https://github.com/murdex5/cub3D.git
cd cub3D

# Clone the minilibx from github
git clone https://github.com/42paris/minilibx-linux.git mlx

# Compile
make
```

### Removal

To remove the compiled binary:

```bash
bash install.sh -r
```

## 🚀 Usage

### Running the Game

```bash
./cub3D <path_to_map_file>
```

### Examples

```bash
# Run with the default map
./cub3D maps/good_maps/map.cub

# Try different themed maps
./cub3D maps/good_maps/creepy.cub
./cub3D maps/good_maps/space_ship.cub
./cub3D maps/good_maps/cube.cub
```

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate view left |
| `→` | Rotate view right |
| `ESC` | Exit game |

## 🗺️ Map Format

Maps are stored in `.cub` files with the following format:

### Map Configuration

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
11000000110111011100000010001
10000000000000001100000010001
10000000000000001101010000N01
1100000111010101111101111000111
1111011111110101 101111010001
11111111 1111111 111111111111
```

### Map Elements

#### Texture Paths
- `NO` - North wall texture (`.xpm` format)
- `SO` - South wall texture
- `WE` - West wall texture
- `EA` - East wall texture

#### Colors
- `F R,G,B` - Floor color in RGB format (0-255)
- `C R,G,B` - Ceiling color in RGB format (0-255)

#### Map Characters
- `1` - Wall
- `0` - Empty space (walkable)
- `N` - Player starting position (facing North)
- `S` - Player starting position (facing South)
- `E` - Player starting position (facing East)
- `W` - Player starting position (facing West)
- ` ` (space) - Empty area outside the map

### Map Rules

✅ **Valid Maps:**
- Must be surrounded by walls (`1`)
- Must contain exactly one player starting position (`N`, `S`, `E`, or `W`)
- Can have irregular shapes
- Spaces outside the playable area are allowed

❌ **Invalid Maps:**
- Open walls (not enclosed)
- Multiple player starting positions
- No player starting position
- Invalid characters
- Invalid RGB color values (> 255)
- Wrong texture file format (not `.xpm`)

#### Note: The texture paths and colour configs can be swapped, but the map should be the last.

## 📁 Project Structure

```
cub3D/
├── checks/          # Map validation and verification
├── errors/          # Error handling and detailed error messages
├── err_files/       # Error message templates
├── frees/           # Memory management
├── init/            # Initialization functions
├── libft/           # Custom C library (submodule)
├── main/            # Main program and hooks
├── maps/            # Map files
│   ├── good_maps/   # Valid example maps
│   └── error_maps/  # Invalid maps for testing
├── mlx/             # MiniLibX library (submodule) // This directory will be automatically installed during the installation 
├── movement/        # Player movement and rotation
├── parser/          # Map and configuration parsing
├── render/          # Ray-casting and rendering
├── textures/        # Texture files (.xpm)
└── utils/           # Utility functions
```

## 🏗️ Technical Details

### Ray-Casting Algorithm

The project implements the **DDA (Digital Differential Analysis)** ray-casting algorithm:

1. **Ray calculation** - Cast rays from the player position for each screen column
2. **Wall detection** - Calculate distance to the nearest wall
3. **Wall height** - Determine wall slice height based on distance
4. **Texture mapping** - Apply appropriate texture based on wall orientation
5. **Rendering** - Draw vertical lines with calculated heights and textures

### Performance

- **Window size**: 960x720 pixels
- **Movement speed**: 0.015 units per frame
- **Rotation speed**: 0.015 radians per frame
- **Real-time rendering** using MiniLibX loop hooks

## 🧪 Testing

The repository includes test maps for validation:

### Good Maps (Valid)
- `maps/good_maps/map.cub` - Standard maze
- `maps/good_maps/cube.cub` - Simple square maze
- `maps/good_maps/creepy.cub` - Creepy themed maze
- `maps/good_maps/space_ship.cub` - Space-themed maze

### Error Maps (Invalid)
- `maps/error_maps/open_walls.cub` - Map with open boundaries
- `maps/error_maps/invalid_chars.cub` - Invalid characters in map
- `maps/error_maps/wrong_colors.cub` - RGB values exceeding 255
- `maps/error_maps/wrong_texture_map.cub` - Wrong texture format

## 🐛 Error Handling

The program provides detailed error messages for:
- **File errors**: Missing or incorrect file format
- **Map errors**: Invalid map structure
- **Texture errors**: Missing or invalid texture files
- **Color errors**: Invalid RGB values
- **Parsing errors**: Configuration format issues

Error messages include references to expected formats in the `err_files/` directory.

## 📚 Dependencies

- **MiniLibX** - Graphics library (included as submodule)
- **libft** - Custom C library (included as submodule)
- **X11** - X Window System libraries
- **Math library** (`-lm`) - For trigonometric calculations

## 🤝 Contributing

This is a school project, but feedback and suggestions are welcome! Feel free to:
- Report bugs by opening an issue
- Suggest improvements
- Share your custom maps

## 📝 License

This project is part of the 42 school curriculum.

## 👨‍💻 Author

**murdex5** <br>
**akmonkee**

*Made with ☕ at 42 School*

---

<div align="center">

### 🎯 42 Project Score: 100!!

*If you found this project helpful, consider giving it a ⭐!*

</div>
