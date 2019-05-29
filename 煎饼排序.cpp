void sortCakes(PancakeStack &x){
    // TODO
    // arrange cakes from small to large.
    int number=x.getStackSize();
	int big;
	int count;
	int index=0;
	while(number){
		count=0;
		big=x.getSizeAtPos(count);
		index=0;
		while(count<number-1){
			count++;
			if(x.getSizeAtPos(count)>big){
				big=x.getSizeAtPos(count);
				index=count;
			}
		}
		x.flip(index);
		x.flip(number-1);
		number--;
	}
}