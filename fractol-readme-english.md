# Fract_ol

## About the Project
Fract_ol is a project that creates fractal visualizations using a graphics library. The main goal is to render beautiful Mandelbrot and Julia sets, allowing users to explore these mathematical wonders interactively.

## What is a Fractal?
Fractals are infinitely complex patterns that are self-similar across different scales. They are created by repeating a simple process over and over in a continuous feedback loop. Despite their complexity, fractals are created using relatively simple mathematical equations.

The most famous examples include the Mandelbrot set and Julia sets, which this project visualizes. These mathematical entities display infinite complexity, allowing you to zoom in forever and discover new details at every level.

## User Guide

### Mandatory Part
```
./fractol [fractal_type]
```

Example usage:
```
./fractol Mandelbrot
./fractol Julia
./fractol Julia -0.6 0.6    # Custom parameter values for Julia set
```

Features:
- Visualization of Mandelbrot and Julia sets
- Panning with WASD and arrow keys
- Center zoom capability with mouse

### Bonus Part (Recommended)
```
./fractol_bonus [fractal_type] [parameters (optional)]
```

Example usage:
```
./fractol_bonus Mandelbrot
./fractol_bonus Julia
./fractol_bonus Julia -0.6 0.6    # Custom parameter values for Julia set
./fractol_bonus Tricorn
./fractol_bonus BurningShip
```

Features:
- More fractal types: Mandelbrot, Julia, Tricorn, Burning Ship, and Dynamic Julia
- Zoom based on mouse position
- Panning with arrow keys
- Color controls and enhancements:
  - G key: Toggle gradient mode (Note: Gradient provides smoother color transitions by calculating color based on exit iteration divided by original iteration)
  - Space: Change color palette
  - J key: Iteration increment mode that increases iteration count with each zoom
  - K key: Turn off iteration increment mode and return to original value

## Controls
- WASD/Arrow Keys: Pan the view
- Mouse Wheel: Zoom in/out
- Space: Change color palette
- G: Toggle gradient mode on/off
- J: Enable iteration increment mode
- K: Disable iteration increment mode

## Recommended Experience

**Special Recommendation:** In the bonus program, first press the G key to activate gradient mode, then press the J key to enable iteration increment feature, and explore the Dynamic Julia fractal with these settings. This combination will show an incredible transformation of colors and details with each zoom in and out, providing a unique visual experience.

When running Julia sets with parameters, you can obtain completely different patterns. Experiment with different parameter values to discover your own unique fractal visuals!

Happy exploring!
