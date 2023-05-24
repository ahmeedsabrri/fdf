FDF - 3D Landscape Representation
#FDF![1684874700305](https://github.com/ahmeedsabrri/fdf/assets/117507574/80e890d7-c329-4aae-9e77-711a448b3e8f)

FDF is a project written in the C programming language that aims to represent a landscape as a 3D object by outlining all its surfaces with lines. This project utilizes the Digital Differential Analyzer (DDA) algorithm to draw lines and matrix rotation techniques for the 3D transformation.

Table of Contents
Introduction
Installation
Usage
File Format
Features
Contributing
License
Introduction
FDF stands for "Fil De Fer," which translates to "Wireframe" in English. The project's main goal is to parse a given map file, interpret the data, and generate a 3D wireframe representation of the landscape using lines.

The program reads the map file, where each number represents a point on the landscape grid. It then connects these points using lines to form a wireframe structure. Additionally, the project incorporates matrix rotation algorithms to allow for a 3D transformation of the rendered landscape.

Installation
Clone the repository:
bash
Copy code
git clone https://github.com/your-username/fdf.git
Change to the project directory:
bash
Copy code
cd fdf
Compile the source code using the provided Makefile:
go
Copy code
make
Usage
After successfully compiling the project, you can run the program with the following command:

bash
Copy code
./fdf maps_file/42.fdf
Replace map_file.fdf with the path to your desired map file.

File Format
The map file provided to the program should follow a specific format. Each line of the file represents a row on the landscape grid, and the numbers on each line represent the height of the corresponding points on that row.

The file should have the following characteristics:

Each line contains the same number of integers.
Integers are separated by spaces.
The integers can be positive or negative.
Here's an example of a valid map file:

Copy code
0 0 0 0 0
0 10 10 10 0
0 10 30 10 0
0 10 10 10 0
0 0 0 0 0
Features
The FDF project offers several features to enhance the rendering of the 3D wireframe landscape:

Basic Line Drawing: The program uses the DDA algorithm to draw lines between the given points, creating a wireframe structure.
3D Transformation: The project implements matrix rotation algorithms to perform a 3D transformation of the rendered landscape.
Zooming: You can zoom in and out of the landscape using the mouse or keyboard controls.
Color Gradient: The program assigns colors to the lines based on the height of the landscape points, creating a color gradient effect.
User Interaction: FDF provides keyboard controls to rotate, move, and modify the landscape's appearance in real-time.
Contributing
Contributions to the FDF project are welcome! If you want to contribute, please follow these steps:

Fork the repository.
Create a new branch for your feature or bug fix.
Make your changes and commit them with descriptive commit messages.
Push your changes to your forked repository.
Open a pull request on the main repository.
