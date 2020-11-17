/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:34:49 by thor              #+#    #+#             */
/*   Updated: 2020/11/17 12:59:28 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

# include "minirt.h"

void		parcing(t_data *type, char **av, int ac);
void		parcing_check(t_data *type, char *line);
void		parcing_tool(t_data *type, int indice, char *line);
void		parc_sphere(t_data *type, char *line);
void		parc_plane(t_data *type, char *line);
void		parc_square(t_data *type, char *line);
void		parc_cylinder(t_data *type, char *line);
void		parc_triangle(t_data *type, char *line);
void		parc_resl(t_data *type, char *line);
void		parc_amb(t_data *type, char *line);
void		parc_camera(t_data *type, char *line);
void		parc_light(t_data *type, char *line);
t_light		*add_light(t_data *type, t_info object);
t_camera	*add_camera(t_data *type, t_info object);
t_objet		*add_sphere(t_data *type, t_info object);
t_objet		*add_plane(t_data *type, t_info object);
t_objet		*add_square(t_data *type, t_info object);
t_objet		*add_cylinder(t_data *type, t_info object);
t_objet		*add_triangle(t_data *type, t_info object);
void		trans_rot(t_data *type, t_objet *new_object, t_info object);
t_vector	rot_vector(t_vector vect_ort, t_vector angle);

#endif
