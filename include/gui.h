/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:02:53 by roduquen          #+#    #+#             */
/*   Updated: 2019/08/29 15:56:01 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# define	ARN_HEIGHT			(1344)
# define	ARN_WIDTH			(1728)
# define	ARN_SIZE			(ARN_WIDTH * ARN_HEIGHT)
# define	CHAR_HEIGHT			(21)
# define	CHAR_WIDTH			(9)
# define	HEIGHT				(1440)
# define	WIDTH				(2560)
# define	SIZE				(WIDTH * HEIGHT)

# include <SDL.h>
# include <SDL_ttf.h>

typedef struct s_gui			t_gui;

struct							s_gui
{
	SDL_Renderer				*renderer;
	SDL_Window					*window;
	SDL_Texture					*texture;
	SDL_Texture					*arn_texture;
	TTF_Font					*font;
	SDL_Surface					*byte[256][5];
	SDL_Texture					*byte_s[256][5];
	SDL_Surface					*bmp;
	uint32_t					*pixels;
	uint32_t					*arn_pixels;
	SDL_Event					event;
	SDL_bool					running;
	int							text_w;
	int							text_h;
	char						string[64][64 + 64 + 64];
	int							pos[4096][2];
};

int								gui(t_gui *data);

/*
**	Console messages
*/

void							ft_print_winner(void);
void							ft_introduce_contestants(void);
int								create_corewar_visual(t_gui *data);

#endif
