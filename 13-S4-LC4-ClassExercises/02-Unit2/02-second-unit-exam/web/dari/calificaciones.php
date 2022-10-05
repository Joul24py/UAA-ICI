<?php include_once 'includes/templates/header.php'; ?>

    <div class="contenedor-barra">
        <h1 class="h1">Lista de calificaciones</h1>

    </div>

    <div class="bg-amarillo contenedor2 sombra">
        <form id="lista" action="#">
            <legend>Ingresa el alumno</legend>
            
            <?php include_once 'includes/Layout/formulario.php'; ?>
            
            
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

                <table id="listado-alumnos" class="listado-alumnos">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Nombre</th>
                            <th>Parcial 1</th>
                            <th>Parcial 2</th>
                            <th>Parcial 3</th>
                            <th>Proyecto</th>
                            <th>Tareas</th>
                            <th>Promedio</th>
                            <th>Acciones</th>
                        </tr>
                    </thead>
                    
                    <tbody>
                        <tr>
                           <td>252511</td>
                           <td>Dariana Gómez Garza</td>
                           <td>10</td>
                           <td>10</td>
                           <td>10</td>
                           <td>10</td>
                           <td>10</td>
                           <td>10</td>
                           
                           
                           <td>
                               <a class="btn-editar btn2"href="editar.php?id=1">Editar</a>
                               
                               <button type="button"class="btn-borrar btn2">Borrar</button>
                               
                           </td>
                           
                            
                        </tr>
                        
                        <tr>
                           <td>252511</td>
                           <td>Dariana Gómez Garza</td>
                           <td>10</td>
                           <td>10</td>
                           <td>10</td>
                           <td>10</td>
                           <td>10</td>
                           <td>10</td>
                           
                           
                           <td>
                               <a  class="btn-editar btn2" href="editar.php?id=1">Editar</a>
                               
                               <button type="button"class="btn-borrar btn2">Borrar</button>
                               
                           </td>
                           
                            
                        </tr>
                    </tbody>
                </table>

            </div>

        </div>
 </div>
   
    </div>


    <?php include_once 'includes/templates/footer.php'; ?>
