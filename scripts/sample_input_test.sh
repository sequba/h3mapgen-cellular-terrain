# This script is intended to test CA on sample input file (with some superwhite and superblack cell)

for p in `seq 3 7`
do
	echo $p
	../randomize 0.$p < maps/mapa_pytlik > maps/p$p.initial
	s='2'
	f='1'
	t=`../pick_threshold $s $f < maps/p$p.initial`
	cp maps/p$p.initial maps/current
        for i in `seq 1 6`
        do
                ../generate $t $s < maps/current > maps/tmp
                mv -f maps/tmp maps/current
                ../draw maps/tmp.bmp < maps/current
                convert maps/tmp.bmp label:"p = 0.$p s = $s t = $t i = $i" -append maps/p$p'i'$i.bmp
        done
        convert maps/p$p'i'{1,2,3,4,5,6}.bmp -append maps/p$p.bmp
done
convert maps/p{3,4,5,6,7}.bmp +append maps/report.png
rm -f maps/current
rm -f maps/*.bmp
