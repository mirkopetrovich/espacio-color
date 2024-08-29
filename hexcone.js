function msg_int(v)
{
	
	for(j=0;j<360;j++) {
		
		k=1-(j/360);
	
	for(i=0;i<60;i++){
		g=Math.floor(i/60*255);
	outlet(0,"setcell",i,j,"val",Math.floor(255*k),Math.floor(g*k),0);
		}
		
		for(i=60;i<120;i++){
		r=Math.floor(255-((i-60)/60*255));
	outlet(0,"setcell",i,j,"val",Math.floor(r*k),Math.floor(255*k),0);
		}
		
		for(i=120;i<180;i++){
		b=Math.floor((i-120)/60*255);
	outlet(0,"setcell",i,j,"val",0,Math.floor(255*k),Math.floor(b*k));
		}
		
		for(i=180;i<240;i++){
		g=Math.floor(255-((i-180)/60*255));
	outlet(0,"setcell",i,j,"val",0,Math.floor(g*k),Math.floor(255*k));
		}
		
			for(i=240;i<300;i++){
		r=Math.floor((i-240)/60*255);
	outlet(0,"setcell",i,j,"val",Math.floor(r*k),0,Math.floor(255*k));
		}
		
			for(i=300;i<360;i++){
		b=Math.floor(255-((i-300)/60*255));
	outlet(0,"setcell",i,j,"val",Math.floor(255*k),0,Math.floor(b*k));
		}
		
		
		
		
		
	}
	outlet(0,"bang");
	
	
	
}
