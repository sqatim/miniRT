/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:41:19 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/09 16:56:16 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int merge(t_colour *data)
{
	return ((data->r * 256 * 256) + (data->g * 256) + data->b);
}

t_colour coleur(t_data *type)
{
	double t1;
	t_objet *tmp;
	t_colour black;
	t_colour phong_s;
	t_colour shadow1;

	t1 = FLT_MAX;
	tmp = type->objet;
	black = make_number(black, 0);
	hit_objet(type, &t1);
	// type->tool.shad = 0;
	if (type->tool.intersect == 1)
	{
		shadow1 = shadows(type, tmp);
		// if (shadow1.r < 1)

		phong_s = phong(type, shadow1);
		type->objet = tmp;
		return (phong_s);
	}
	else
		return (black);
}

void minirt(t_data *type)
{
	int i;
	t_colour colour;

	i = 0;
	type->rsl.x = 0;
	type->rsl.y = 0;
	while (type->rsl.y < type->rsl.height)
	{
		type->rsl.x = 0;
		while (type->rsl.x < type->rsl.width)
		{
			camera_setting(type);
			ray(type);
			colour = coleur(type);
			type->colour.r = (int)colour.r;
			type->colour.g = (int)colour.g;
			type->colour.b = (int)colour.b;
			type->mlx.img_data[i] = merge(&type->colour);
			type->rsl.x++;
			i++;
		}
		type->rsl.y++;
	}
}
