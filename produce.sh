for p in `seq 1 9`
	for t in `seq 1 9`
		echo $p $t
		./mapgen 33 33 0.$p > maps/p$p't'$t.initial
		cp maps/p$p't'$t.initial maps/p$p't'$t.current
		./bmpgen maps/p$p't'$t'i'0.bmp  < maps/p$p't'$t.initial
		for i in `seq 1 5` 
		do
			./automata $t < maps/p$p't'$t.current > maps/p$p't'$t.tmp
			cp maps/p$p't'$t.tmp maps/p$p't'$t.current
			./bmpgen maps/p$p't'$t'i'$i.bmp < maps/p$p't'$t.tmp
		done
		rm -f maps/p$p't'$t.tmp
		rm -f maps/p$p't'$t.initial
		rm -f maps/p$p't'$t.current
		convert label:"p = $p t = $t" maps/p$p't'$t'i'{1,2,3,4,5}.bmp -append maps/p$p't'$t.bmp 
	done
done
convert maps/p{1,2,3,4,5,6,7,8,9}t{1,2,3,4,5,6,7,8,9}.bmp +append maps/all.png
