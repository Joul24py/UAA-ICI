<?php
	require('conexion.php');	
?>
<!DOCTYPE html>
  <html>
    <head>
      <meta charset="utf-8">
      <title>resultados</title>
	</head>
    <body>
<h1>RESULTADOS</h1>
<a href="https://localhost/v0/ferv0/index.php">agregar un nuevo alumno</a>
<?php
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
		$actualizar="UPDATE  calificaciones SET lista='$nlist', nombre='$nom', apellido_paterno='$ap1', apellido_materno='$ap2', parcial1='$par1', parcial2='$par2', parcial3='$par3', proyecto='$proy', tareas='$tare', calificacion_final='$calfin', faltas='$fal'  WHERE lista='$nlist'";
	$rs=$mysqli->query($actualizar);
if($rs==0) echo "error al guardar datos";
	$query="SELECT * FROM calificaciones order by lista asc";
	$resultado=$mysqli->query($query);
?>
<table>
<tr>
<td> NUMERO DE LISTA </td>
<td>nombre</td>
<td>apellído paterno</td>
<td>apellído materno</td>
<td>parcial 1 (25%)</td>
<td>parcial 2 (25%)</td>
<td>parcial 3 (25%)</td>
<td>proyecto (20%)</td>
<td>tareas (5%)</td>
<td>calificacion final (100%)</td>
<td>faltas</td>
</tr> 
<?php while($row=$resultado->fetch_assoc()){ ?>
					<tr>
					<td><?php echo $row['lista'];?></td>
					<td><?php echo $row['nombre'];?></td>
					<td><?php echo $row['apellido_paterno'];?></td>
					<td><?php echo $row['apellido_materno'];?></td>
					<td><?php echo $row['parcial1'];?></td>
					<td><?php echo $row['parcial2'];?></td>
					<td><?php echo $row['parcial3'];?></td>
					<td><?php echo $row['proyecto'];?></td>
					<td><?php echo $row['tareas'];?></td>
					<td><?php echo $row['calificacion_final'];?></td>
					<td><?php echo $row['faltas'];?></td>
							<td><a href="modificar.php?id=<?php echo $row['lista'];?>"><input type='button' value='EDITAR' name='submit'></a></td>
									</tr>
					<?php } ?>
</table>
<p></p>
</body>
</html>