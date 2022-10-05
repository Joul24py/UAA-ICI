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
	require('conexion.php');	
$datos=$_POST;
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