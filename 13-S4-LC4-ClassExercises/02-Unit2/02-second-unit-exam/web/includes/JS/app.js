const formularioAlumnos=document.querySelector('#lista');

eventListeners();
function eventListeners(){
    //cuando el formulario de crear o editar se ejecuta
   
 formularioAlumnos.addEventListener('submit', leerFormulario);
}

function leerFormulario(e){
    
    e.preventDefault;
    //leer los datos de inputs
    
    const primero=document.querySelector('#primero').value,
          nombre=document.querySelector('#nombre').value,
          parcial1=document.querySelector('#parical1').value,
          parcial2=document.querySelector('#parcial2').value,
          parcial3=document.querySelector('#parcial3').value,
          proyecto=document.querySelector('#proyecto').value,
          tareas=document.querySelector('#tareas').value;
          
    
    if( primero === '' || nombre === ''|| parcial1 === '' || parcial2 === '' || parcial3 === '' || proyecto === '' || tareas === '')
    {
        console.log("El campo está vacío");
    }
    else{
        console.log('tiene algo');
    }
    
    
}