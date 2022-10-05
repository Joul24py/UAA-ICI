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
        <?php include_once 'includes/templates/header.php'; ?>
        
        <?php
        require ('conexion.php');
        $nl=$_GET['id'];
            $query="SELECT * FROM calificaciones where lista='$nl'";
            $resultado=$mysqli->query($query);
            $row=$resultado->fetch_assoc();	
        ?>
	    
	    <div class="contenedor-barra">
            <div class="contenedor2 barra2">
                <a href="calificaciones2.php" class="btn2 volver">Volver</a>
                <h1 class="h1">Editar Alumno</h1>
            </div>
        </div>

        <div class="bg-amarillo contenedor2 sombra">
            <form ACTION="modificado.php" METHOD="POST">
                <legend><span> Edite el Alumno</span> </legend>
    
                    <div class="campos">

                        <div class="Campo">
                            <label for="lista">Número de lista: </label>
                            <input type="text" name="lista" id="lista" value="<?php echo $nl; ?>" placeholder="Número de lista">
                        </div>

                        <div class="Campo">
                            <label for="nombre">Nombre:</label>
                            <input type="text" name="nombre" id="nombre" value="<?php echo $row['nombre']; ?>" placeholder="Nombre del alumno">
                        </div>

                        <div class="Campo">
                            <label for="apellido_paterno">Apellido paterno:</label>
                            <input type="text" name="apeP" id="apellido_paterno" value="<?php echo $row['apellido_paterno']; ?>" placeholder="Primer apellido del alumno">
                        </div>

                        <div class="Campo">
                            <label for="apellido_materno">Apellido materno:</label>
                            <input type="text" name="apeM" id="apellido_materno" value="<?php echo $row['apellido_materno']; ?>" placeholder="Segundo apellido del alumno">
                        </div>

                        <div class="Campo">
                            <label for="parcial1">Primer Parcial:</label>
                            <input type="number" name="p1" min="0" max="10" value="<?php echo $row['parcial1']; ?>" >
                        </div>

                        <div class="Campo">
                            <label for="parcial2">Segundo Parcial:</label>
                            <input type="number" name="p2" min="0" max="10" value="<?php echo $row['parcial2']; ?>" >
                        </div>

                        <div class="Campo">
                            <label for="parcial3">Tercer Parcial:</label>
                            <input type="number" name="p3" min="0" max="10" value="<?php echo $row['parcial3']; ?>" >
                        </div>

                        <div class="Campo">
                            <label for="proyecto">Proyecto:</label>
                            <input type="number" name="pro" min="0" max="10" value="<?php echo $row['proyecto']; ?>" >
                        </div>

                        <div class="Campo tareas">
                            <label for="tareas">Tareas:</label>
                            <input type="number" name="tar" min="0" max="10" value="<?php echo $row['tareas']; ?>" >
                        </div>

                        <div class="Campo">
                            <label for="faltas">Faltas:</label>
                            <input type="text" name="falt" id="faltas" value="<?php echo $row['faltas']; ?>" onkeypress='return validaNumericos(event)'/>         
                        </div>

                        <div class="Campo enviar">
                            <input type="submit" value="Añadir">
                        </div>

                    </div>
            </form>
        </div>

        <?php include_once 'includes/templates/footer.php'; ?>

    </body>
</html>