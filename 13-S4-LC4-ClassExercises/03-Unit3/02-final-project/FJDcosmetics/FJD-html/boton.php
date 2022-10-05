<?php
$n = 0; //esta variable servira para saber cuantas unidades del producto quiere el usuario, se incrementara cada que el usuario de click en el boton de añadir al carrito. esta variable tambien se muestra en el boton para que el usuario se de cuenta cuantas unidades de ese producto ha agregado
//tambien estaba planiando poner otro boton que aparecicera despues de agregar la primer unidad, que diga quitar del carrito, por si el usuario se arrepiente o agrega una unidad de mas 
if(isset($_POST['Submit'])){ //esta condicion se da cuenta cuando el boton ha sido precionado, esto es lo que aun no me funciona no comprendo porque
echo "el boton ha sido precionado"; //esto lo puse solo para comprobar si el boton era precionado y si el programa entraba al if, lo cual no hace... se puede borrar sin problemas esta instruccion
$nl=$_GET['id']; //esto recorre el ID del producto enviado por el boton, el ID sera enviado desde la base de datos ayudado por el boton de añadir al carrito
//se comprueba que el valor enviado sea igual al identificador, y se incrementa la variable n
//aqui tambien se tendria que llamar la base de datos para extraer el identificador 
if($nl==99) ++$n;
}
?>
<DOCTYPE HTML>
<html>
<head>
<meta charset="UTF-8">
<title> PRUEBA BOTON</title>
</head>
<body>
<h1> BOTON AGREGAR PRODUCTOS</h1>

    <a href="boton.php" id="99"> <input type='button' value='<?php echo "Agregar al carrito $n"; ?>' name='Submit' id='Submit'></a>
    <?php
//esto tambien lo use como para ver si si entraba al if al precionar el boton, pero no se por que no entra 
if(isset($_POST['Submit'])){
	echo "<h2>el boton ha sido precionado</h2>"; 
 }
 else
 {
	 echo "<h2> no se ha precionado el boton </h2>";
 }
	 ?>
</body>
</html>