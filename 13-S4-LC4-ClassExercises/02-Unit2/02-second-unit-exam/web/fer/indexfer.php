  <!DOCTYPE html>
  <html>
    <head>
      <meta charset="utf-8">
      <title>REGISTRO DE ALUMNOS</title>
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
<a href="https://localhost/v0/ferv0/resultados.php">ir a la pagina de resultados</a>
	<FORM ACTION="guardar_datos.php" METHOD="POST">  
            <fieldset>
                <legend>Información Personal</legend>
                <label for="lista">NUMERO DE LISTA: </label>
                <input type="text" name="lista" id="lista" placeholder="Tu Numero de lista">
                <label for="nombre">Nombre:</label>
                <input type="text" name="nombre" id="nombre" placeholder="Tu Nombre">
                                <label for="apellido_paterno">APELLÍDO PATERNO:</label>
<input type="text" name="apeP" id="apellido_paterno" placeholder="tu apellído paterno">
                <label for="apellido_materno">APELLÍDO MATERNO:</label>
                <input type="text" name="apeM" id="apellido_materno" placeholder="tu apellído materno">
            </fieldset>
            <fieldset>
                <legend>calificaciones</legend>
                <label for="parcial1">parcial1:</label>
                <input type="number" name="p1" min="0" max="10">
                <label for="parcial2">parcial2:</label>
                <input type="number" name="p2" min="0" max="10" >
                <label for="parcial3">parcial3:</label>
                <input type="number" name="p3" min="0" max="10" >
                <label for="proyecto">proyecto:</label>
                <input type="number" name="pro" min="0" max="10" >
                <label for="tareas">tareas:</label>
                <input type="number" name="tar" min="0" max="10" >
                <label for="faltas">faltas:</label>
<input type="text" name="falt" id="faltas" onkeypress='return validaNumericos(event)'/>            </fieldset>
            <input type="submit" value="ENVIAR" >
        </form>
  

	</body>
	</html>