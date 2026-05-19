# 🏆 Contestas.io
> **Quiz Interativo via Terminal em C — Arquitetura e Fluxo de Execução**

---

## 💡 1. O Conceito Pedagógico

O objetivo principal do projeto é a **separação estrita entre Dados (Persistência) e Lógica (Código)**. 
* O arquivo `perguntas.txt` funciona como um banco de dados independente.
* O motor em C consome, processa e gerencia esses dados em memória dinâmica, permitindo atualizações em tempo real sem a necessidade de recompilar o executável.

---

## 🏗️ 2. Ciclo de Vida dos Dados e Fluxo do Programa
*(Utilize este diagrama linear para mostrar à banca exatamente como os dados entram, são processados e persistem)*

```mermaid
flowchart TD
    %% Customização de Estilos (Clean e Profissional)
    classDef arquivo fill:#fff5f5,stroke:#ffc9c9,stroke-width:2px;
    classDef memoria fill:#e6f7ff,stroke:#bae7ff,stroke-width:2px;
    classDef loop fill:#f6ffed,stroke:#d9f7be,stroke-width:2px;

    %% Elementos
    A["📄 perguntas.txt <br> (Leitura dos blocos de 7 linhas)"]:::arquivo
    B["🧠 Alocação Dinâmica <br> (malloc calculado via RAM)"]:::memoria
    C["🎲 Pré-Jogo <br> (Função Recursiva: Embaralhar)"]:::loop
    D["⚙️ Loop Principal do Jogo <br> (Mecânicas: ⏱️ Tempo Limite 10s | 🔥 Multiplicador Combo)"]:::loop
    E["🏆 ranking.txt <br> (Persistência do Top 10 Ordenado)"]:::arquivo
    
    F["👨‍🏫 Interface: Modo Professor <br> (Inserção de novas questões)"]:::memoria

    %% Conexões do Fluxo Principal
    A -->|1. fopen 'r'| B
    B -->|2. Vetor de Structs| C
    C -->|3. Dados Misturados| D
    D -->|4. Gravação via fscanf/fprintf| E

    %% Conexão do Modo Professor
    F -->|Modo Append 'a'| A
