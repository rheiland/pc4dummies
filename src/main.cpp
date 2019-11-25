
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <omp.h>
#include <fstream>
#include <random>

const char* hdr = R"foo(<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!-- Created with PhysiCell (http://PhysiCell.MathCancer.org/) -->
<svg 
 xmlns:dc="http://purl.org/dc/elements/1.1/" 
 xmlns:cc="http://creativecommons.org/ns#" 
 xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#" 
 xmlns:svg="http://www.w3.org/2000/svg" 
 xmlns="http://www.w3.org/2000/svg" 
 version="1.1" 
 width="2000" 
 height="2140" 
 id="svg2">
  <rect x="0" y="0" width="2000" height="2140" stroke-width="4" stroke="white" fill="white"/>
  <text x="25" y="60"
   font-family="Arial" font-size="50" fill="black" >
   Current time: 0 days, 0 hours, and 0.00 minutes, z = 0.00 &#956;m
  </text>
  <text x="25" y="115"
   font-family="Arial" font-size="47.5" fill="black" >
   513 agents
  </text>
 <g id="tissue" 
    transform="translate(0,2140) scale(1,-1)">
  <g id="ECM">
  </g>
  <g id="cells">
   <g id="cell0">
  <circle cx="1058.58" cy="1178.26" r="8.41271" stroke-width="0.5" stroke="black" fill="limegreen"/>
  <circle cx="1058.58" cy="1178.26" r="5.05167" stroke-width="0.5" stroke="none" fill="limegreen"/>
   </g>
)foo";
const char* footer = R"foo(</g>
</g>
  <rect x="1750" y="2070" width="200" height="20" stroke-width="4" stroke="rgb(255,255,255)" fill="rgb(0,0,0)"/>
  <text x="1762.5" y="2057.5"
   font-family="Arial" font-size="50" fill="black" >
   200 &#956;m
  </text>
  <text x="50" y="2090"
   font-family="Arial" font-size="37.5" fill="black" >
   0 days, 0 hours, 0 minutes, and 0.0161 seconds
  </text>
  <rect x="0" y="140" width="2000" height="2000" stroke-width="4" stroke="rgb(0,0,0)" fill="none"/>
</svg>
)foo";

int main( int argc, char* argv[] )
{
	std::cout << std::endl << "Start... " << std::endl; 
	char filename[1024];
	std::ofstream myfile;
	for (int idx=1; idx<10; idx++)
	{
		// sprintf( filename , "%s/initial" , PhysiCell_settings.folder.c_str() ); 
		sprintf( filename , "snapshot%08d.svg" , idx ); 
		std::cout << filename << std::endl; 

		myfile.open (filename);
		myfile << hdr;
   		// myfile << "<g id="cell0">\n";
//    <g id="cell0">
		for (int icell=1; icell<500; icell++)
		{

   		myfile << "<g id='cell" << icell << "'>\n";
  		// myfile << "<circle cx='1058.58' cy='1178.26' r='8.41271' stroke-width='0.5' stroke='black' fill='limegreen'/>";
		//   <circle cx="1058.58" cy="1178.26" r="5.05167" stroke-width="0.5" stroke="none" fill="limegreen"/>
		double xrand = 2000* ((double)rand()/(double)RAND_MAX); 
		double yrand = 2000* ((double)rand()/(double)RAND_MAX); 
  		myfile << "<circle cx='" << xrand << "' cy='" << yrand << "' r='8.' stroke-width='0.5' stroke='black' fill='limegreen'/>\n";
   		myfile << "</g>\n";
		}

		myfile << footer;
		myfile.close();
	}
	std::cout << std::endl << "Done. " << std::endl; 
	return 0;
}
