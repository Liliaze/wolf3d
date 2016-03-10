/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_key.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:43:21 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/09 12:19:08 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_AND_KEY_H
# define COLOR_AND_KEY_H

# define BLACK		0x00000000
# define BROWN		0x00663300
# define GREY		0x007F7F7F
# define WHITE		0x00FFFFFF
# define RED		0x00FF0000
# define ORANGE		0x00FFBC00
# define YELLOW		0x00FFFF00
# define GREEN		0x0000FF00
# define GREENF		0x0000FF88
# define CYAN		0x0033FFFF
# define BLUE		0x0011AAFF
# define BLUEF		0x001111FF
# define PINK		0x00ED22ED
# define SALMON		0x00FF7F7F
# define PURPLE 	0x00882289

# define ECHAP		53
# define ENTER		36
# define DEL		51
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define W			13
# define A			0
# define S			1
# define D			2
# define Q			12
# define E			14
# define LESS		78
# define MORE		69
# define SPACE		49
# define ONE		83
# define TWO		84
# define THREE		85
# define ONE2		18
# define TWO2		19
# define THREE2		20

# define KEYPRESSM		(1L<<0)
# define KEYRELEASEM	(1L<<1)
# define BUTPRESSM		(1L<<2)
# define BUTRELEASEM	(1L<<3)
# define ENTERWM		(1L<<4)
# define LEAVEWM		(1L<<5)
# define BUT1MOTIONM	(1L<<8)
# define BUT2MOTIONM	(1L<<9)
# define BUT3MOTIONM	(1L<<10)
# define BUT4MOTIONM	(1L<<11)
# define BUT5MOTIONM	(1L<<12)
# define BUTMOTIONM		(1L<<13)

# define KEYPRESS		2
# define KEYRELEASE		3
# define BUTTONPRESS	4
# define BUTTONRELEASE	5
# define MOTIONOTIFY	6
# define FOCUSIN		9
# define FOCUSOUT		10
# define EXPOSE			12
# define GRAPHICSEXPOSE	13
# define NOEXPOSE		14
# define LASTEVENT		35

#endif
