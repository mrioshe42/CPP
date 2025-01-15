/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:20:16 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/21 18:20:46 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Calculate the area of a triangle using the cross product method
static Fixed area(Point const a, Point const b, Point const c) {
    Fixed area = ((b.getX() - a.getX()) * (c.getY() - a.getY()) - 
                  (c.getX() - a.getX()) * (b.getY() - a.getY())) / Fixed(2);
    if (area < Fixed(0))
        area = area * Fixed(-1);
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate area of the main triangle
    Fixed abcArea = area(a, b, c);
    
    // Calculate areas of three triangles formed by the point and two vertices
    Fixed pabArea = area(point, a, b);
    Fixed pbcArea = area(point, b, c);
    Fixed pcaArea = area(point, c, a);
    
    // Check if point is on any edge or vertex
    if (pabArea == Fixed(0) || pbcArea == Fixed(0) || pcaArea == Fixed(0))
        return false;
    
    // Point is inside if sum of three areas equals the main triangle area
    Fixed sumAreas = pabArea + pbcArea + pcaArea;
    
    return sumAreas == abcArea;
}