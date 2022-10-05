<!DOCTYPE html>
  <html>
    <head>
        <meta charset="utf-8">
        <title>UAAGRADES</title>
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

            <div class="contenedor-barra">
                <h1 class="h1">Lista de calificaciones</h1>

            </div>

            <div class="bg-amarillo contenedor2 sombra">
                <form ACTION="guardar_datos.php" METHOD="POST">
                    <legend>Ingresa el alumno</legend>
    
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

            </div>

           <!-----------------------------> 
            <div class="bg-blanco contenedor sombra alumnos">
                <div class="contenedor-alumnos h1">
                    <h2 class="h2">Alumnos</h2>
                    <input type="text" id="buscar" class="buscador sombra" placeholder="Buscar alumnos...">

                    <div class="letra-color">
                        <p class="total-alumnos"> <span>2</span> Alumnos</p>
                        <div class="contenedor-tabla">
                            <?php
                                require('conexion.php');	
                            $datos=$_POST;
                                $query="SELECT * FROM calificaciones order by lista asc";
                                $resultado=$mysqli->query($query);
                            ?>
                            <table id="listado-alumnos" class="listado-alumnos">
                                <thead>
                                    <tr>
                                        <th>Número de lista</th>
                                        <th>Nombre</th>
                                        <th>Ap. paterno</th>
                                        <th>Ap. materno</th>
                                        <th>Parcial 1</th>
                                        <th>Parcial 2</th>
                                        <th>Parcial 3</th>
                                        <th>Proyecto</th>
                                        <th>Tareas</th>
                                        <th>Promedio</th>
                                        <th>Faltas</th>
                                        <th>Acciones</th>
                                    </tr>
                                </thead>

                                <tbody>
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
                                            <td>
                                                <a  class="btn-editar btn2" href="editar.php?id=<?php echo $row['lista'];?>">Editar</a>
                                                <button type="button"class="btn-borrar btn2">Borrar</button>
                                            </td>
                                        </tr>
                                    <?php } ?>
                                </tbody>

                            </table>

                        </div>

                    </div>
                </div>
                
                <h2>REPROBADOS POR PROMEDIO</h2>
                <?php if(MySQLi_num_rows($resultado2)==0) 	echo "<p>NO HAY PERSONAS REPROBADAS POR PROMEDIO</p>"; 
                else {
                ?>
                    <table>
                        <tr>
                        <td> NUMERO DE LISTA </td>
                        <td>nombre</td>
                        <td>apellído paterno</td>
                        <td>apellído materno</td>
                        <td>calificacion final (100%)</td>
                        </tr> 
                        <?php while($row2=$resultado2->fetch_assoc()){ ?>
                            <tr>
                            <td><?php echo $row2['lista'];?></td>
                            <td><?php echo $row2['nombre'];?></td>
                            <td><?php echo $row2['apellido_paterno'];?></td>
                            <td><?php echo $row2['apellido_materno'];?></td>
                            <td><?php echo $row2['calificacion_final'];?></td>
                                            </tr>
                            <?php } ?>
                    </table>
                    <?php } ?>

                <h2>REPROBADOS POR FALTAS</h2>
                <?php if(MySQLi_num_rows($resultado3)==0) 	echo "<p>NO HAY PERSONAS REPROBADAS POR FALTAS</p>"; 
                else {
                ?>
                    <table>
                        <tr>
                        <td> NUMERO DE LISTA </td>
                        <td>nombre</td>
                        <td>apellído paterno</td>
                        <td>apellído materno</td>
                        <td>faltas</td>
                        </tr> 
                        <?php 
                        while($row3=$resultado3->fetch_assoc()){ ?>
                            <tr>
                            <td><?php echo $row3['lista'];?></td>
                            <td><?php echo $row3['nombre'];?></td>
                            <td><?php echo $row3['apellido_paterno'];?></td>
                            <td><?php echo $row3['apellido_materno'];?></td>
                            <td><?php echo $row3['faltas'];?></td>
                                            </tr>
                            <?php } ?>
                    </table>
                <?php } ?>

            </div>

        <?php include_once 'includes/templates/footer.php'; ?>
    </body>
</html>