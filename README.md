
#FDF![1684874700305](https://github.com/ahmeedsabrri/fdf/assets/117507574/80e890d7-c329-4aae-9e77-711a448b3e8f)

# FDF - 3D Landscape Representation

FDF is a project written in the C programming language that aims to represent a landscape as a 3D object by outlining all its surfaces with lines. This project utilizes the Digital Differential Analyzer (DDA) algorithm to draw lines and matrix rotation techniques for the 3D transformation.

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [File Format](#file-format)
- [Features](#features)
- [Contributing](#contributing)
- [License](#license)

## Introduction

FDF stands for "Fil De Fer," which translates to "Wireframe" in English. The project's main goal is to parse a given map file, interpret the data, and generate a 3D wireframe representation of the landscape using lines.

The program reads the map file, where each number represents a point on the landscape grid. It then connects these points using lines to form a wireframe structure. Additionally, the project incorporates matrix rotation algorithms to allow for a 3D transformation of the rendered landscape.

## Installation

1. Clone the repository:

```
git clone https://github.com/your-username/fdf.git
```

2. Change to the project directory:

```
cd fdf
```

3. Compile the source code using the provided Makefile:

```
make
```

## Usage

After successfully compiling the project, you can run the program with the following command:

```
./fdf maps_file/42.fdf
```

## File Format

The map file provided to the program should follow a specific format. Each line of the file represents a row on the landscape grid, and the numbers on each line represent the height of the corresponding points on that row.

The file should have the following characteristics:

- Each line contains the same number of integers.
- Integers are separated by spaces.
- The integers can be positive or negative.

Here's an example of a valid map file:

```
0 0 0 0 0
0 10 10 10 0
0 10 30 10 0
0 10 10 10 0
0 0 0 0 0
```

## Features

The FDF project offers several features to enhance the rendering of the 3D wireframe landscape:

- **Basic Line Drawing**: The program uses the DDA algorithm to draw lines between the given points, creating a wireframe structure.
- **3D Transformation**: The project implements matrix rotation algorithms to perform a 3D transformation of the rendered landscape.
- **Zooming**: You can zoom in and out of the landscape using the mouse or keyboard controls.
- **Color Gradient**: The program assigns colors to the lines based on the height of the landscape points, creating a color gradient effect.
- **User Interaction**: FDF provides keyboard controls to rotate, move, and modify the landscape's appearance in real-time.

## Contributing

Contributions to the FDF project are welcome! If you want to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them with descriptive commit messages.
4. Push your changes to your forked repository.
5. Open a pull request on the main repository.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). You can find the full license text in the [LICENSE](LICENSE) file.
