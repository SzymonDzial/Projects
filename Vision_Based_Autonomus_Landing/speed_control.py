
from simpful import *

# skrypt z funkcjami sterującymi prędkościami na podstawie logiki rozmytej
# utworzenie obiektu klasy FuzzySystem
def create_fuzzy_xy():
    FS = FuzzySystem()

    s1=5
    s2=8

    # zdefiniowanie wejściowych zmiennych rozmytych
    S_1 = FuzzySet(function=Triangular_MF(a=-s2, b=-s2, c=-s1), term="mfar")
    S_2 = FuzzySet(function=Triangular_MF(a=-s2, b=-s1, c=0), term="mmedium")
    S_3 = FuzzySet(function=Triangular_MF(a=-s1, b=0, c=s1), term="close")
    S_4 = FuzzySet(function=Triangular_MF(a=0, b=s1, c=s2), term="medium")
    S_5 = FuzzySet(function=Triangular_MF(a=s1, b=s2, c=s2), term="far")
    FS.add_linguistic_variable("lxy", LinguisticVariable([S_1, S_2, S_3,S_4,S_5], concept="lxy", universe_of_discourse=[-s2,s2]))

    d1=1
    d2=2

    # zdefiniowanie wyjściowych zmiennych rozmytych
    T_1 = FuzzySet(function=Triangular_MF(a=-d2, b=-d2, c=-d1), term="mfast")
    T_2 = FuzzySet(function=Triangular_MF(a=-d2, b=-d1, c=0), term="maverage")
    T_3 = FuzzySet(function=Triangular_MF(a=-d1, b=0, c=d1), term="slow")
    T_4 = FuzzySet(function=Triangular_MF(a=0, b=d1, c=d2), term="average")
    T_5 = FuzzySet(function=Triangular_MF(a=d1, b=d2, c=d2), term="fast")
    FS.add_linguistic_variable("vxy", LinguisticVariable([T_1, T_2, T_3,T_4,T_5], universe_of_discourse=[-d2,d2]))

    # zdefiniowanie reguł
    R1 = "IF (lxy IS close) THEN (vxy IS slow)"
    R2 = "IF (lxy IS medium) THEN (vxy IS average)"
    R3 = "IF (lxy IS far) THEN (vxy IS fast)"
    R4 = "IF (lxy IS mmedium) THEN (vxy IS maverage)"
    R5 = "IF (lxy IS mfar) THEN (vxy IS mfast)"

    FS.add_rules([R1, R2, R3, R4, R5])
    return FS

def create_fuzzy_z():
    FS = FuzzySystem()

    s1=5
    s2=8

    # zdefiniowanie wejściowych zmiennych rozmytych
    S_1 = FuzzySet(function=Triangular_MF(a=-s2, b=-s2, c=-s1), term="mfar")
    S_2 = FuzzySet(function=Triangular_MF(a=-s2, b=-s1, c=0), term="mmedium")
    S_3 = FuzzySet(function=Triangular_MF(a=-s1, b=0, c=s1), term="close")
    S_4 = FuzzySet(function=Triangular_MF(a=0, b=s1, c=s2), term="medium")
    S_5 = FuzzySet(function=Triangular_MF(a=s1, b=s2, c=s2), term="far")
    FS.add_linguistic_variable("lxy", LinguisticVariable([S_1, S_2, S_3,S_4,S_5], concept="lxy", universe_of_discourse=[-s2,s2]))

    d1=0.5
    d2=1.5

    # zdefiniowanie wyjściowych zmiennych rozmytych
    T_1 = FuzzySet(function=Triangular_MF(a=-d2, b=-d2, c=-d1), term="mfast")
    T_2 = FuzzySet(function=Triangular_MF(a=-d2, b=-d1, c=0), term="maverage")
    T_3 = FuzzySet(function=Triangular_MF(a=-d1, b=0, c=d1), term="slow")
    T_4 = FuzzySet(function=Triangular_MF(a=0, b=d1, c=d2), term="average")
    T_5 = FuzzySet(function=Triangular_MF(a=d1, b=d2, c=d2), term="fast")
    FS.add_linguistic_variable("vxy", LinguisticVariable([T_1, T_2, T_3,T_4,T_5], universe_of_discourse=[-d2,d2]))

    # zdefiniowanie reguł
    R1 = "IF (lxy IS close) THEN (vxy IS slow)"
    R2 = "IF (lxy IS medium) THEN (vxy IS average)"
    R3 = "IF (lxy IS far) THEN (vxy IS fast)"
    R4 = "IF (lxy IS mmedium) THEN (vxy IS maverage)"
    R5 = "IF (lxy IS mfar) THEN (vxy IS mfast)"

    FS.add_rules([R1, R2, R3, R4, R5])
    return FS

def fuzzy_ctr(FS,l):
    # ustawienie zmiennych
    FS.set_variable("lxy", l)

    # wyliczanie prędkości sposobem "Mamdani inference" 
    return FS.Mamdani_inference(["vxy"])["vxy"]