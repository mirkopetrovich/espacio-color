function msg_int(v)
{
	for (i=0;i<v+1;i++) {
		j=i%64
		k=Math.floor(i/64);
		r=Math.floor(255-((i/4096)*255));
		g=Math.floor(i/4096*255);
		b=Math.floor(i/4096*255);
	outlet(0,"setcell",j,k,"val",r,g,b);
	}
	outlet(0,"bang");
}