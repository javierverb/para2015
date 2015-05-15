$x=50;
$y=70;

print "\n";
print "BEFORE subrutine.\n";
print "x --> $x\n";
print "y --> $y\n";
print "\n";

print "START subrutine\n";
&interchange ($x, $y);
print "END subrutine\n";
print"\n";

print "AFTER subrutine.\n";
print "x:$x y:$y\n";

print "\nEl programa realiza pasaje por referencia(call_by_reference)\n";
print "el valor de las variables sufre modificacion fuera de la subrutina\n\n";

sub interchange {
my($x1, $y1) = @_;
print "--parameters--\n";
print "\t x1: $x1\n\t y1: $y1\n";
@_[0] = $y1;
@_[1] = $x1; 
#local $z1;
#$z1 = $x1;
#$x1 = $y1;
#$y1 = $z1;

print "after operations in subrutine\n";
print "\t x1:$x1\n\t y1:$y1\n";
}

#esto hace la profe, tiene que ser pasaje por referencia
#my($a, $b) = @_;
#@_[0] = $b;
#@_[1] = $a;
