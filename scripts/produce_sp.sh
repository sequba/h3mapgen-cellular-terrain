# Script runs CA for a number of parameters and presents the results on a big png image

for p in `seq 1 6`
do
	../random 33 33 0.$p > maps/p$p.initial
	for s in `seq 1 5`
	do
			f='1'
			t=`../pick_threshold $s $f < maps/p$p.initial`
			echo $p $s
			cp maps/p$p.initial maps/current
			for i in `seq 1 6` 
			do
				../generate $t $s < maps/current > maps/tmp
				mv -f maps/tmp maps/current
			done
			../draw maps/tmp.bmp < maps/current
			convert maps/tmp.bmp label:"p = 0.$p s = $s t = $t i = 6" -append maps/s$s'p'$p.bmp
	done
done

for s in `seq 1 5`
do
	convert maps/s$s'p'{1,2,3,4,5,6}.bmp -append maps/s$s.bmp
done

convert maps/s{1,2,3,4,5}.bmp +append maps/sp1.png
rm -f maps/current
rm -f maps/*.bmp
