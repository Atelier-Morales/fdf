/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 00:34:45 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/04 17:30:01 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <mlx.h>
# define BUFF_SIZE 90960
# define COLOR 0x666666
# define X_POS 600
# define Y_POS 100
# define X_SIZ 30
# define Y_SIZ 20
# define WIN_X 1500
# define WIN_Y 1000
# define IMG_X 1500
# define IMG_Y 1000

typedef struct		s_coord
{
	double			x;
	double			y;
	double			y_i;
	double			x_i;
	int				z;
	int				j;
	signed int		degrade;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_matrix
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
}					t_matrix;

typedef struct		s_list
{
	char			**content;
	struct s_list	*next;
}					t_list;

typedef struct		s_img
{
	unsigned int	width;
	unsigned int	height;
	int				bpp;
	int				sizeline;
	int				endian;
	void			*img;
	char			*data;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				fd;
	char			*data;
	char			**value;
	int				openwin;
	int				i;
	int				j;
	int				x_move;
	int				y_move;
	int				z_move;
	double			rot;
	t_coord			*ptr;
	t_list			*lst;
}					t_env;

int					main(int ac, char **av);
int					get_next_line(int const fd, char **line);
size_t				ft_strlen(const char *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				draw_columns(void *img, t_coord *ptr, int i);
void				draw_lines(void *img, t_coord *ptr, int i);
void				mlx_pixel_put_to_image(void *img, int x, int y, \
					unsigned long color);
void				addnode(t_list **s, char **name);
t_list				*duplicate_struct(t_list *ptr);
t_coord				*duplicate_list(t_coord *ptr);
void				stock_xy(t_coord **ptr, t_env *e, int z);
t_coord				*compute_coord_plus(t_env e);
void				compute_coord(t_env *e);
int					key_hook(int keycode, t_env *e);
void				start_drawing(void *img, t_coord *ptr, int i);
void				initialize_mlx(void **mlx, void **img);
void				initialize_win(void **win, void *mlx, void *img);
int					main(int ac, char **av);
int					expose_hook(t_env *e);

#endif
