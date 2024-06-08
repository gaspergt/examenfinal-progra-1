#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Alumno {
    std::string carne;
    std::string nombre;
    int edad;
    char sexo;
    int matematicas;
    int ciencias;
    int computacion;
    int fisica;
    int idioma;
    int literatura;
};

void ingresarDatos(std::vector<Alumno>& alumnos) {
    alumnos = {
        {"18-00001", "Juan Lopez", 19, 'M', 73, 65, 78, 91, 82, 73},
        {"18-00002", "Carlos Suarez", 20, 'M', 54, 61, 67, 42, 69, 70},
        {"18-00003", "Karla Sanchez", 18, 'F', 90, 88, 85, 78, 94, 79},
        {"18-00004", "Ana Perez", 19, 'F', 35, 58, 63, 67, 61, 52},
        {"18-00005", "Jose Juarez", 22, 'M', 62, 59, 68, 62, 65, 71},
        {"18-00006", "Daniel Perez", 21, 'M', 67, 75, 86, 76, 72, 86},
        {"18-00007", "Deina Ovando", 19, 'F', 57, 64, 61, 69, 71, 63},
        {"18-00008", "Orlando Xu", 17, 'M', 82, 83, 78, 75, 89, 95},
        {"18-00009", "Miguel Perez", 20, 'M', 78, 82, 72, 65, 69, 81},
        {"18-00010", "Alex Carrillo", 24, 'M', 49, 62, 69, 72, 75, 79}
    };
}

void contarSexo(const std::vector<Alumno>& alumnos) {
    int hombres = std::count_if(alumnos.begin(), alumnos.end(), [](const Alumno& alumno) {
        return alumno.sexo == 'M';
    });

    int mujeres = std::count_if(alumnos.begin(), alumnos.end(), [](const Alumno& alumno) {
        return alumno.sexo == 'F';
    });

    std::cout << "Alumnos hombres: " << hombres << std::endl;
    std::cout << "Alumnos mujeres: " << mujeres << std::endl;
}

void alumnoMasJoven(const std::vector<Alumno>& alumnos) {
    auto it = std::min_element(alumnos.begin(), alumnos.end(), [](const Alumno& a, const Alumno& b) {
        return a.edad < b.edad;
    });

    int menorEdad = it->edad;

    std::cout << "Alumno(s) mas joven(es):" << std::endl;
    for (const auto& alumno : alumnos) {
        if (alumno.edad == menorEdad) {
            std::cout << alumno.nombre << std::endl;
        }
    }
}

void clasesReprobadasCarlosSuarez(const std::vector<Alumno>& alumnos) {
    auto it = std::find_if(alumnos.begin(), alumnos.end(), [](const Alumno& alumno) {
        return alumno.nombre == "Carlos Suarez";
    });

    if (it != alumnos.end()) {
        const Alumno& carlosSuarez = *it;
        int reprobadas = 0;
        if (carlosSuarez.matematicas < 61) reprobadas++;
        if (carlosSuarez.ciencias < 61) reprobadas++;
        if (carlosSuarez.computacion < 61) reprobadas++;
        if (carlosSuarez.fisica < 61) reprobadas++;
        if (carlosSuarez.idioma < 61) reprobadas++;
        if (carlosSuarez.literatura < 61) reprobadas++;
        std::cout << "Carlos Suarez reprobo " << reprobadas << " curso(s)." << std::endl;
    }
}

void alumnosAprobaronTodosCursos(const std::vector<Alumno>& alumnos) {
    std::cout << "Alumnos que aprobaron todos los cursos:" << std::endl;
    for (const auto& alumno : alumnos) {
        if (alumno.matematicas >= 61 && alumno.ciencias >= 61 &&
            alumno.computacion >= 61 && alumno.fisica >= 61 &&
            alumno.idioma >= 61 && alumno.literatura >= 61) {
            std::cout << alumno.nombre << std::endl;
        }
    }
}

void alumnoConPromedioMasAlto(const std::vector<Alumno>& alumnos) {
    double mayorPromedio = 0.0;
    for (const auto& alumno : alumnos) {
        double promedio = (alumno.matematicas + alumno.ciencias + alumno.computacion +
                           alumno.fisica + alumno.idioma + alumno.literatura) / 6.0;
        mayorPromedio = std::max(mayorPromedio, promedio);
    }

    std::cout << "Alumno(s) con el promedio mas alto:" << std::endl;
    for (const auto& alumno : alumnos) {
        double promedio = (alumno.matematicas + alumno.ciencias + alumno.computacion +
                           alumno.fisica + alumno.idioma + alumno.literatura) / 6.0;
        if (promedio == mayorPromedio) {
            std::cout << alumno.nombre << " con promedio de " << std::fixed << std::setprecision(2) << promedio << std::endl;
        }
    }
}

void alumnoConPromedioMasBajo(const std::vector<Alumno>& alumnos) {
    double menorPromedio = std::numeric_limits<double>::max();
    for (const auto& alumno : alumnos) {
        double promedio = (alumno.matematicas + alumno.ciencias + alumno.computacion +
                           alumno.fisica + alumno.idioma + alumno.literatura) / 6.0;
        menorPromedio = std::min(menorPromedio, promedio);
    }

    std::cout << "Alumno(s) con el promedio mas bajo:" << std::endl;
    for (const auto& alumno : alumnos) {
        double promedio = (alumno.matematicas + alumno.ciencias + alumno.computacion +
                           alumno.fisica + alumno.idioma + alumno.literatura) / 6.0;
        if (promedio == menorPromedio) {
            std::cout << alumno.nombre << " con promedio de " << std::fixed << std::setprecision(2) << promedio << std::endl;
        }
    }
}

void promedioMatematicas(const std::vector<Alumno>& alumnos) {
    double suma = 0.0;
    for (const auto& alumno : alumnos) {
        suma += alumno.matematicas;
    }
    double promedio = suma / alumnos.size();
    std::cout << "Promedio en el curso de Matematicas: " << std::fixed << std::setprecision(2) << promedio << std::endl;
}

void mejorPromedioPorSexo(const std::vector<Alumno>& alumnos) {
    double mayorPromedioM = 0.0, mayorPromedioF = 0.0;
    std::string mejorHombre, mejorMujer;

    for (const auto& alumno : alumnos) {
        double promedio = (alumno.matematicas + alumno.computacion + alumno.fisica) / 3.0;
        if (alumno.sexo == 'M' && promedio > mayorPromedioM) {
            mayorPromedioM = promedio;
            mejorHombre = alumno.nombre;
        }
        if (alumno.sexo == 'F' && promedio > mayorPromedioF) {
            mayorPromedioF = promedio;
            mejorMujer = alumno.nombre;
        }
    }

    std::cout << "Hombre con el mayor promedio en Matematicas, Computacion y Fisica: " << mejorHombre << " con promedio de " << std::fixed << std::setprecision(2) << mayorPromedioM << std::endl;
    std::cout << "Mujer con el mayor promedio en Matemáticas, Computacion y Fisica: " << mejorMujer << " con promedio de " << std::fixed << std::setprecision(2) << mayorPromedioF << std::endl;
}

void alumnoQueReproboMasCursos(const std::vector<Alumno>& alumnos) {
    int maxReprobadas = 0;
    std::string peorAlumno;
    std::vector<std::string> cursosReprobados;

    for (const auto& alumno : alumnos) {
        int reprobadas = 0;
        std::vector<std::string> cursos;
        if (alumno.matematicas < 61) { reprobadas++; cursos.push_back("Matematicas"); }
        if (alumno.ciencias < 61) { reprobadas++; cursos.push_back("Ciencias"); }
        if (alumno.computacion < 61) { reprobadas++; cursos.push_back("Computacion"); }
        if (alumno.fisica < 61) { reprobadas++; cursos.push_back("Fisica"); }
        if (alumno.idioma < 61) { reprobadas++; cursos.push_back("Idioma"); }
        if (alumno.literatura < 61) { reprobadas++; cursos.push_back("Literatura"); }

        if (reprobadas > maxReprobadas) {
            maxReprobadas = reprobadas;
            peorAlumno = alumno.nombre;
            cursosReprobados = cursos;
        }
    }

    std::cout << "Alumno que reprobo mas cursos: " << peorAlumno << " con " << maxReprobadas << " curso(s) reprobado(s): ";
    for (const auto& curso : cursosReprobados) {
        std::cout << curso << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Alumno> alumnos;
    ingresarDatos(alumnos);

    contarSexo(alumnos);
    alumnoMasJoven(alumnos);
    clasesReprobadasCarlosSuarez(alumnos);
    alumnosAprobaronTodosCursos(alumnos);
    alumnoConPromedioMasAlto(alumnos);
    alumnoConPromedioMasBajo(alumnos);
    promedioMatematicas(alumnos);
    mejorPromedioPorSexo(alumnos);
    alumnoQueReproboMasCursos(alumnos);

    return 0;
}
