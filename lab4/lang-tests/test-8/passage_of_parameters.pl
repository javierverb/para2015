$x=50;
$y=70;

print "\n";
print "before subrutine.\n";
print "x --> $x\n";
print "y --> $y\n";
print "\n";

print "start subrutine\n";
&interchange ($x, $y);
print "\n";

print "after subrutine\n";
print "x:$x y:$y\n";
print "\nse agrego codigo suficiente para demostrar que Perl funciona por call_by_value\n";
print "el valor de las variables no sufre modificacion fuera de la subrutina\n";
print " se podria hacer call_by_reference pero abria que modificar las el codigo base??\n\n";

sub interchange {
($x1, $y1) = @_;
local $z1;
$z1 = $x1;
$x1 = $y1;
$y1 = $z1;

print "into subrutine\n";
print "x1:$x1 y1:$y1\n";
}