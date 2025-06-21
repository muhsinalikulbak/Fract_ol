/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:23:18 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/01 14:53:22 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

// Define key codes for keyboard input
# define EVENT_CLOSE_BTN 17 // Close button
# define EXPOSE 12 // Expose event
# define KEY_ESC 65307 // Escape key
# define KEY_W 119 // W key for moving up
# define KEY_A 97 // A key for moving left
# define KEY_S 115 // S key for moving down
# define KEY_D 100 // D key for moving right
# define KEY_UP 65362 // Up arrow key
# define KEY_DOWN 65364 // Down arrow key
# define KEY_LEFT 65361 // Left arrow key
# define KEY_RIGHT 65363 // Right arrow key
# define KEY_J 106 // J key for increasing iterations
# define KEY_K 107 // K key for resetting iterations
# define KEY_G 103 // G key for toggling gradient
# define KEY_SPACE 32 // Space key for changing palette
# define KEY_ONE 49 // 1 key for selecting Mandelbrot
# define KEY_TWO 50 // 2 key for selecting Julia
# define KEY_THREE 51 // 3 key for selecting Tricorn
# define KEY_FOUR 52 // 4 key for selecting Burning Ship
# define KEY_FIVE 53 // 5 key for selecting Dynamic Julia
# define SCROOL_UP 4 // Scroll up for zooming in
# define SCROOL_DOWN 5 // Scroll down for zooming out

#endif