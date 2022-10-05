  <!DOCTYPE html>
  <html>
    <head>
      <meta charset="utf-8">
      <title>MODIFICAR</title>
    <script>		
	function soloNumeros(e)
{
	var key = window.Event ? e.which : e.keyCode
	return ((key >= 48 && key <= 57) || (key==8))
}
	</script>
	</head>
    <body>
	<H1> REGISTRO DE CALIFICACIONES DE ALUMNOS DE ICI</H1>
<?php
require ('conexion.php');
$nl=$_GET['id'];
	$query="SELECT * FROM calificaciones where lista='$nl'";
	$resultado=$mysqli->query($query);
	$row=$resultado->fetch_assoc();	
?>
	<FORM ACTION="modificado.php" METHOD="POST">  
            <fieldset>
                <legend>Información Personal</legend>
                <label for="lista">NUMERO DE LISTA: </label>
                <input type="text" name="lista" id="lista" value="<?php echo $nl; ?>" placeholder="Tu Numero de lista">
                <label for="nombre">Nombre:</label>
                <input type="text" name="nombre" id="nombre" value="<?php echo $row['nombre']; ?>" placeholder="Tu Nombre">
                                <label for="apellido_paterno">APELLÍDO PATERNO:</label>
<input type="text" name="apeP" id="apellido_paterno" value="<?php echo $row['apellido_paterno']; ?>" placeholder="tu apellído paterno">
                <label for="apellido_materno">APELLÍDO MATERNO:</label>
                <input type="text" name="apeM" id="apellido_materno" value="<?php echo $row['apellido_materno']; ?>" placeholder="tu apellído materno">
            </fieldset>
            <fieldset>
                <legend>calificaciones</legend>
                <label for="parcial1">parcial1:</label>
                <input type="number" name="p1" min="0" max="10" value="<?php echo $row['parcial1']; ?>" >
                <label for="parcial2">parcial2:</label>
                <input type="number" name="p2" min="0" max="10" value="<?php echo $row['parcial2']; ?>" >
                <label for="parcial3">parcial3:</label>
                <input type="number" name="p3" min="0" max="10" value="<?php echo $row['parcial3']; ?>" >
                <label for="proyecto">proyecto:</label>
                <input type="number" name="pro" min="0" max="10" value="<?php echo $row['proyecto']; ?>" >
                <label for="tareas">tareas:</label>
                <input type="number" name="tar" min="0" max="10" value="<?php echo $row['tareas']; ?>" >
                <label for="faltas">faltas:</label>
<input type="text" name="falt" id="faltas" value="<?php echo $row['faltas']; ?>" onkeypress='return validaNumericos(event)'/>            
</fieldset>
            <input type="submit" value="ENVIAR" >
        </form>
  

	</body>
	</html>