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
    <form ACTION="guardar_datos.php" METHOD="POST">
    
    <div class="campos">
    
        <div class="Campo">
            <label for="lista">Número de lista: </label>
            <input type="text" name="lista" id="lista" placeholder="Número de lista">
        </div>
        
        <div class="Campo">
            <label for="nombre">Nombre:</label>
            <input type="text" name="nombre" id="nombre" placeholder="Nombre del alumno">
        </div>
        
        <div class="Campo">
            <label for="apellido_paterno">Apellido paterno:</label>
            <input type="text" name="apeP" id="apellido_paterno" placeholder="Primer apellido del alumno">
        </div>
        
        <div class="Campo">
            <label for="apellido_materno">Apellido materno:</label>
            <input type="text" name="apeM" id="apellido_materno" placeholder="Segundo apellido del alumno">
        </div>
        
        <div class="Campo">
            <label for="parcial1">Primer Parcial:</label>
            <input type="number" name="p1" min="0" max="10">
        </div>
        
        <div class="Campo">
            <label for="parcial2">Segundo Parcial:</label>
            <input type="number" name="p2" min="0" max="10" >
        </div>
        
        <div class="Campo">
            <label for="parcial3">Tercer Parcial:</label>
            <input type="number" name="p3" min="0" max="10" >
        </div>
        
        <div class="Campo">
            <label for="proyecto">Proyecto:</label>
                <input type="number" name="pro" min="0" max="10" >
        </div>
        
        <div class="Campo tareas">
            <label for="tareas">Tareas:</label>
            <input type="number" name="tar" min="0" max="10" >
        </div>
        
        <div class="Campo">
            <label for="faltas">Faltas:</label>
            <input type="text" name="falt" id="faltas" onkeypress='return validaNumericos(event)'/>            
        </div>
        
        <div class="Campo enviar">
            <input type="submit" value="Añadir">
        </div>
    
    </div>
        
    </form>

	</body>
	
</html>