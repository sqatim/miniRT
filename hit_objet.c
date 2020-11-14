/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:16:55 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/14 14:35:26 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		just_calcul(t_data *type, double has_inter)
{
	t_objet *tmp;

	while (type->objet->i != type->tool.index)
		type->objet = type->objet->next;
	if (type->objet->type == sphere_d)
		sphere_p_n(type, has_inter);
	else if (type->objet->type == plane_d)
		plane_p_n(type, has_inter);
	else if (type->objet->type == square_d)
		square_p_n(type, has_inter);
	else if (type->objet->type == cylinder_d)
		cylinder_p_n(type, has_inter);
	else if (type->objet->type == triangle_d)
		triangle_p_n(type, has_inter);
}

double		object_sp_cy(t_data *type, t_objet *tmp, t_ray *ombre)
{
	double	save;
	t_objet	*temporaire;

	temporaire = tmp;
	if (type->tool.type == sphere_d || type->tool.type == cylinder_d)
	{
		while (temporaire->i != type->tool.index)
			temporaire = temporaire->next;
		if (type->tool.type == sphere_d)
			save = hit_sphere(temporaire, ombre);
		if (type->tool.type == cylinder_d)
			save = hit_cylinder(temporaire, ombre);
		temporaire = tmp;
		return (save);
	}
	return (0);
}

static void	check_shadow(t_data *type, double save, int *index)
{
	if (save == 0)
	{
		if (*index == 0)
		{
			*index = 1;
			type->shad.intersect = 1;
			type->shad.degre += 0.5;
		}
	}
}

void		hit_objet2(t_data *type, t_ray *ombre, t_objet *tmp)
{
	int		index;
	double	save;
	double	has_inter;
	t_objet	*temporaire;

	temporaire = tmp;
	index = 0;
	has_inter = 0;
	save = object_sp_cy(type, tmp, ombre);
	while (temporaire != NULL)
	{
		if (temporaire->i == type->tool.index)
			temporaire = temporaire->next;
		if (temporaire != NULL)
		{
			witch_object(temporaire, ombre, &has_inter);
			if (has_inter > 0 && has_inter <= ombre->lenght)
				check_shadow(type, save, &index);
			temporaire = temporaire->next;
		}
	}
}

void		hit_objet(t_data *type, double *t1)
{
	t_ray	*ray;
	t_objet	*tmp;
	double	has_inter;

	ray = &type->ray;
	type->tool.type = 0;
	tmp = type->objet;
	type->tool.intersect = 0;
	has_inter = 0;
	while (type->objet != NULL)
	{
		witch_object(type->objet, ray, &has_inter);
		if (has_inter > 0 && has_inter < *t1)
		{
			type->tool.type = type->objet->type;
			*t1 = has_inter;
			type->tool.index = type->objet->i;
			type->objet->t = has_inter;
			type->tool.intersect = 1;
		}
		type->objet = type->objet->next;
	}
	type->objet = tmp;
	if (type->tool.intersect == 1)
		just_calcul(type, has_inter);
}
