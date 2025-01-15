/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:19:26 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/21 18:38:11 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();
		Point(const float x, const float y);
		Fixed getX() const;
		Fixed getY() const;
};
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif