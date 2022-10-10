<?php

<?php
	session_start();
	include('config.php');

	$query=$conn->query("select * from user where id='".$_SESSION['usuario']."'");
	$row=$query->fetch_array();

	$usuario=$row['Nombre'];
?>

<h1> Bienvenido </h1>
<a href="Logout.php"> Salir de la sesión </a>

