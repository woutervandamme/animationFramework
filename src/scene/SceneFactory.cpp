/*
 * SceneFac-tory.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: wouter
 */

#include "SceneFactory.h"
#include <fstream>
#include "shape/DynamicCircle.h"
#include "shape/GravityCircle.h"
#include "shape/Boid.h"
#include "shape/Flock.h"
#include <string>
#include <iostream>
Scene & SceneFactory::createScene(std::string filename, const WorldWindow & window){
	std::ifstream inf(filename.c_str());

    if(!inf){
        throw "File could not be opened: "+filename;
    }

    Scene * scene = new Scene;
    scene->addDrawable(&window);

    Colour colour;
    while(inf){
        std::string keyword;
        inf >> keyword;
        if(keyword == "colour"){
            double r, g, b;
            inf >> r >> g >> b;
            colour = Colour(r,g,b);
        }else if(keyword == "circle"){
            double puntx, punty, radius;
            inf >> puntx >> punty >> radius;
            Circle * circle = new Circle(Point(puntx, punty), radius,colour);
            scene->addDrawable(circle);
        }else if(keyword == "dynamicCircle"){
            double puntx, punty, radius, velocityx, velocityy;
            inf >> puntx >> punty >> radius >> velocityx >> velocityy;
            DynamicCircle * circle = new DynamicCircle(Point(puntx, punty), radius, colour, Vector(velocityx, velocityy));
            scene->addDrawable(circle);
            scene->addAnimatable(circle);
        } else if(keyword == "boid"){
        	double puntx,punty,size,velocityx,velocityy;
        	inf >> puntx >> punty >> size >> velocityx >> velocityy;
        	Boid * boid = new Boid(Point(puntx,punty),colour,Vector(velocityx,velocityy),size);
        	scene->addDrawable(boid);
        	scene->addAnimatable(boid);
        } else if (keyword == "gravCircle"){
        	double puntx, punty, radius, velocityx, velocityy;
        	inf >> puntx >> punty >> radius >> velocityx >> velocityy;
        	GravityCircle * circle = new GravityCircle(Point(puntx, punty), radius, colour, Vector(velocityx, velocityy));
        	scene->addDrawable(circle);
        	scene->addAnimatable(circle);
        } else if(keyword == "flock"){
        	double amount,puntx,punty,size,velocityx,velocityy;
        	inf >> amount;
        	Flock * flock = new Flock(colour);

        	for(int i = 0; i < amount; i++){
        		inf >> puntx >> punty >> size >> velocityx >> velocityy;
        		Boid * boid = new Boid(Point(puntx,punty),colour,Vector(velocityx,velocityy),size);
            	flock->addBoid(boid);
        	}

        	scene->addDrawable(flock);
        	scene->addAnimatable(flock);
        }
    }
    return *scene;
}
