
main =
	do
		function_b 3
		

function_a :: Integer -> IO Integer
function_a z = 
	do
		let result = z + var_global
		return result

function_b :: Integer -> Integer
function_b y = 
	do
		let var_global = y+1
		function_a (var_global*y)
