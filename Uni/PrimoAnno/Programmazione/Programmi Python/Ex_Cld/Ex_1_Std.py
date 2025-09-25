def insert_students(students_list: list ,student):
    students_list.append(student)
    print(students_list)

def cancel_students(students_list,student):
    students_list.remove(student)
    print(students_list)

students_list=[]
nome="Mario"
eta="18"
classe="5a"
student={"nome":nome,"eta":eta,"classe":classe}

insert_students(students_list,student)
cancel_students(students_list,student)


    