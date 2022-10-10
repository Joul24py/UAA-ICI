#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                         Graficación
                           8° "A"
                         Tarea final
                Docente: Hermilo Sánchez Cruz
         Alumnos:
                 Espinoza Sánchez Joel Alejandro
                 Flores Fernández Óscar Alonso
                 Gómez Garza Dariana
                 González Arenas Fernando Francisco
Fecha de Entrega: Aguascalientes, Ags., 17 de junio del 2022
Descripción:
'''
#%% Librerías e inicio del while
import cv2
import functions2d
import functions3d

runProgram = 1
while runProgram == 1:
    
    #%% Menú inicial
    print("TAREA FINAL")
    print("0. Salir")
    print("Archivo:")
    print("  a) Abrir la imagen a manipular")
    print("    1. 001.bmp (2D)")
    print("    2. 002.bmp (2D)")
    print("    3. 003.bmp (2D)")
    print("    4. 004.bmp (2D)")
    print("    5. 005.bmp (2D)")
    print("    6. Armadillo.txt (3D)")
    print("    7. Bunny.txt (3D)")
    print("    8. Dragon.txt (3D)")
    print("    9. Drill.txt (3D)")
    print("    10. Happy.txt (3D)")
    imageOption = 2
    
    #%% Operaciones para 2D
    if imageOption >= 1 and imageOption <= 5:
        image = functions2d.openImage2d(imageOption)
        print("Operaciones para 2D")
        print("0. Salir")
        print("Euler:")
        print("  1. a) Característica de Euler")
        print("  2. c) Número de 1-pixeles")
        print("  3. d) Número de tetrapixeles")
        print("  4. e) Número de vértices")
        print("Códigos de cadena:")
        print("  5. a) F8")
        print("  6. b) F4")
        print("  7. c) VCC")
        print("  8. d) 3OT")
        print("  9. e) AF8")
        print("Morfología matemática:")
        print("  10. a) Erosión")
        print("  11. b) Dilatación")
        print("  12. c) Clausura")
        print("  13. d) Cerradura")
        print("  14. e) Adelgazamiento")
        operationOption = 1
        
        # Característica de Euler
        if operationOption == 1:
            print("Característica de Euler:")
            image = functions2d.openImage2d(imageOption)
            euler = functions2d.calcEuler2D(image, len(image), len(image[0]), imageOption)
            print("  Característica de Euler:")
            print("  " + str(euler))
        
        # Número de 1-pixeles
        if operationOption == 2:
            print("Número de 1-píxeles:")
            image = functions2d.openImage2d(imageOption)
            one_pixels, zero_pixels = functions2d.calcOnePixels(image)
            print("  Número de 1-píxeles:")
            print("  " + str(one_pixels))
            print("  Número de 0-píxeles:")
            print("  " + str(zero_pixels))
        
        # Número de tetrapíxeles
        if operationOption == 3:
            print("Número de tetrapíxeles:")
            image = functions2d.openImage2d(imageOption)
            tetrapixels = functions2d.calcTetrapixels(image)
            print("  Número de tetrapíxeles:")
            print("  " + str(tetrapixels))
        
        # Número de vértices
        if operationOption == 4:
            print("Número de vértices:")
            image = functions2d.openImage2d(imageOption)
            vertexes = functions2d.calcVertexes(image)
            print("  Número de vértices:")
            print("  " + str(vertexes))
        
        # Código de cadena F8
        if operationOption == 5:
            print("Código de cadena F8:")
            image = functions2d.openImage2d(imageOption)
            newImage = functions2d.calcPerimeter_8(image, len(image), len(image[0]))
            chainF8 = functions2d.chainF8(newImage)
            print("  Código de cadena F8:")
            print("  " + str(chainF8))
        
        # Código de cadena F4
        if operationOption == 6:
            print("Código de cadena F4:")
            image = functions2d.openImage2d(imageOption)
            newImage = functions2d.calcPerimeter_8(image, len(image), len(image[0]))
            chainF4 = functions2d.chainF4(newImage)
            print("  Código de cadena F4:")
            print("  " + str(chainF4))
        
        # Código de cadena VCC
        if operationOption == 7:
            print("Código de cadena VCC:")
            image = functions2d.openImage2d(imageOption)
            newImage = functions2d.calcPerimeter_8(image, len(image), len(image[0]))
            chainVCC = functions2d.chainVCC(newImage)
            print("  Código de cadena VCC:")
            print("  " + str(chainVCC))
        
        # Código de cadena 3OT
        if operationOption == 8:
            print("Código de cadena 3OT:")
            image = functions2d.openImage2d(imageOption)
            newImage = functions2d.calcPerimeter_8(image, len(image), len(image[0]))
            chain3OT = functions2d.chain3OT(newImage)
            print("  Código de cadena 3OT:")
            print("  " + str(chain3OT))
        
        # Código de cadena AF8
        if operationOption == 9:
            print("Código de cadena AF8:")
            image = functions2d.openImage2d(imageOption)
            newImage = functions2d.calcPerimeter_8(image, len(image), len(image[0]))
            chainAF8 = functions2d.chainAF8(newImage)
            print("  Código de cadena VCC:")
            print("  " + str(chainAF8))
        
        # Erosión
        if operationOption == 10:
            print("Erosión:")
            image1 = functions2d.openImage2d(imageOption)
            image2 = functions2d.openImage2d(imageOption)
            newImage = functions2d.erosion2d(image1, image2)
            print("  Erosión:")
            print("  Hecha en result.txt")
        
        # Dilatación
        if operationOption == 11:
            print("Dilatación:")
            image1 = functions2d.openImage2d(imageOption)
            image2 = functions2d.openImage2d(imageOption)
            newImage = functions2d.dilation2d(image1, image2)
            print("  Dilatación:")
            print("  Hecha en result.txt")
        
        # Cerradura
        if operationOption == 12:
            print("Cerradura:")
            image1 = functions2d.openImage2d(imageOption)
            image2 = functions2d.openImage2d(imageOption)
            newImage1 = functions2d.erosion2d(image1, image2)
            newImage2 = functions2d.erosion2d(image1, image2)
            image = functions2d.dilation2d(newImage1, newImage2)
            print("  Cerradura:")
            print("  Hecha en result.txt")
        
        # Clausura
        if operationOption == 13:
            print("Clausura:")
            image1 = functions2d.openImage2d(imageOption)
            image2 = functions2d.openImage2d(imageOption)
            newImage1 = functions2d.erosion2d(image1, image2)
            newImage2 = functions2d.erosion2d(image1, image2)
            image = functions2d.dilation2d(newImage1, newImage2)
            print("  Clausura:")
            print("  Hecha en result.txt")
        
        # Adelgazamiento
        if operationOption == 14:
            print("Adelgazamiento:")
    
    #%% Operaciones para 3D
    if imageOption >= 6 and imageOption <= 10:
        image = functions3d.openImage3d(imageOption)
        print("Operaciones para 3D")
        print("0. Salir")
        print("Euler:")
        print("  1. a) Característica de Euler")
        print("  2. b) Número de hoyos o túneles")
        print("  3. c) Número de 1-voxeles")
        print("  4. d) Número de tetravoxeles")
        print("  5. e) Número de vértices")
        print("Morfología matemática:")
        print("  6. a) Erosión")
        print("  7. b) Dilatación")
        print("  8. c) Clausura")
        print("  9. d) Cerradura")
        print("  10. e) Adelgazamiento")
        operationOption = 1
        
        # Característica de Euler
        if operationOption == 1:
            image = functions3d.openImage3d(imageOption)
            surface = functions3d.calcSurface(image)
            image = functions3d.openImage3d(imageOption)
            one_voxels, zero_voxels = functions3d.calcOneVoxels(image)
            image = functions3d.openImage3d(imageOption)
            tetravoxels = functions3d.calcTetravoxels(image)
            image = functions3d.openImage3d(imageOption)
            octavoxels = functions3d.calcOctavoxels(image)
            euler = (surface / 2) - (2 * one_voxels) + tetravoxels - octavoxels
            print(euler)
        
        # Número de túneles
        if operationOption == 2:
            print("Número de túneles:")
            tunnels = functions3d.calcTunnels(image, imageOption - 6)
            print("  Número de túneles:")
            print("  " + str(tunnels))
        
        # Número de 1-voxeles
        if operationOption == 3:
            print("Número de 1-voxeles:")
            image = functions3d.openImage3d(imageOption)
            one_voxels, zero_voxels = functions3d.calcOneVoxels(image)
            print("  Número de 1-voxeles:")
            print("  " + str(one_voxels))
            print("  Número de 0-voxeles:")
            print("  " + str(zero_voxels))
        
        # Número de tetravoxeles
        if operationOption == 4:
            print("Número de tetravoxeles:")
            image = functions3d.openImage3d(imageOption)
            tetravoxels = functions3d.calcTetravoxels(image)
            image = functions3d.openImage3d(imageOption)
            octavoxels = functions3d.calcOctavoxels(image)
            print("  Número de tetravoxeles:")
            print("  " + str(tetravoxels))
            print("  Número de octavoxeles:")
            print("  " + str(octavoxels))
        
        # Número de vértices
        if operationOption == 5:
            print("Número de vértices:")
            image = functions3d.openImage3d(imageOption)
            vertexes = functions3d.calcVertexes3d(image)
            print("  Número de vértices:")
            print("  " + str(vertexes))
        
        # Erosión
        if operationOption == 6:
            print("Erosión:")
            image1 = functions3d.openImage3d(imageOption)
            image2 = functions3d.openImage3d(imageOption)
            newImage = functions3d.erosion3d(image1, image2)
            print("  Erosión:")
            print("  Hecha en result.txt")
        
        # Dilatación
        if operationOption == 7:
            print("Dilatación:")
            image1 = functions3d.openImage3d(imageOption)
            image2 = functions3d.openImage3d(imageOption)
            newImage = functions3d.dilation3d(image1, image2)
            print("  Dilatación:")
            print("  Hecha en result.txt")
        
        # Cerradura
        if operationOption == 8:
            print("Cerradura:")
            image1 = functions3d.openImage3d(imageOption)
            image2 = functions3d.openImage3d(imageOption)
            newImage1 = functions3d.erosion3d(image1, image2)
            newImage2 = functions3d.erosion3d(image1, image2)
            image = functions3d.dilation3d(newImage1, newImage2)
            print("  Cerradura:")
            print("  Hecha en result.txt")
        
        # Clausura
        if operationOption == 9:
            print("Clausura:")
            image1 = functions3d.openImage3d(imageOption)
            image2 = functions3d.openImage3d(imageOption)
            newImage1 = functions3d.erosion3d(image1, image2)
            newImage2 = functions3d.erosion3d(image1, image2)
            image = functions3d.dilation3d(newImage1, newImage2)
            print("  Clausura:")
            print("  Hecha en result.txt")
        
        # Adelgazamiento
        if operationOption == 10:
            print("Adelgazamiento:")
        
    runProgram = 0 # ELIMINAR ESTA LÍNEA EN EL ENTREGABLE Y PONER OPERATIONOPTION E IMAGEOPTION COMO INPUTS
    
    if imageOption < 0 or imageOption > 10:
        print("Opción inválida")
        continue
    
    if (imageOption == 0) or (operationOption == 0):
        print("Saliendo del programa")
        runProgram = 0