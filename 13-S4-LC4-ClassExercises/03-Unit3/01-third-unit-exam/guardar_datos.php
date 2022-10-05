<?php
    require('conexion.php');
    $datos=$_POST;
    $calfin=$datos['p1']*0.25+$datos['p2']*0.25+$datos['p3']*0.25+$datos['pro']*0.20+$datos['tar']*0.05;
    $nlist=$datos['lista'];
    $nom=$datos['nombre'];
    $ap1=$datos['apeP'];
    $ap2=$datos['apeM'];
    $par1=$datos['p1'];
    $par2=$datos['p2'];
    $par3=$datos['p3'];
    $proy=$datos['pro'];
    $tare=$datos['tar'];
    $fal=$datos['falt'];
    $insertar="INSERT INTO calificaciones VALUES( '$nlist', '$nom', '$ap1', '$ap2', '$par1', '$par2', '$par3', '$proy', '$tare', '$calfin', '$fal' )";
	$rs=$mysqli->query($insertar);

    if($rs==0) echo "Error al guardar los datos";
    header ("Location: https://localhost/Examen2P/calificaciones.php");
?>
