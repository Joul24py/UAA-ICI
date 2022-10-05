const formularioAlumnos=document.querySelector('#lista');

eventListeners();
function eventListeners(){
    //cuando el formulario de crear o editar se ejecuta
   
 formularioAlumnos.addEventListener('submit', leerFormulario);
}

// Eliminar el Contacto
function eliminarContacto(e) {
     if( e.target.parentElement.classList.contains('btn-borrar') ) {
          // tomar el ID
          const lista = e.target.parentElement.getAttribute('data-id');

          // console.log(id);
          // preguntar al usuario
          const respuesta = confirm('¿Estás Seguro(a)? Se eliminará un elemento ');

          if(respuesta) {
               // llamado a ajax
               // crear el objeto
               const xhr = new XMLHttpRequest();

               // abrir la conexión
               xhr.open('GET', `calificaciones2.php?id=${lista}&accion=borrar`, true);

               // leer la respuesta
               xhr.onload = function() {
                    if(this.status === 200) {
                         const resultado = JSON.parse(xhr.responseText);
                      
                         if(resultado.respuesta == 'correcto') {
                              // Eliminar el registro del DOM
                              console.log(e.target.parentElement.parentElement.parentElement);
                              e.target.parentElement.parentElement.parentElement.remove();

                              // mostrar Notificación
                              mostrarNotificacion('Contacto eliminado', 'correcto');

                            
                         } else {
                              // Mostramos una notificacion
                              mostrarNotificacion('Hubo un error...', 'error' );
                         }

                    }
               }

               // enviar la petición
               xhr.send();
          }
     }
}