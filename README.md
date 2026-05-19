# 🏆 Contestas.io
> **Apresentação do Projeto - Quiz Interativo via Terminal em C**

---

## 💡 1. O Insight Pedagógico e os Super Bônus

* **Separação de Dados e Lógica:** O motor do jogo em C é 100% independente do banco de dados. O professor pode gerenciar perguntas sem tocar em uma única linha de código.
* **🚀 Entregas de Nota Extra Implementadas:**
  * **🏷️ Categorias Dinâmicas:** Cada pergunta possui sua própria etiqueta de assunto.
  * **⏱️ Tempo Limite Real:** Integração com a biblioteca `<time.h>` para validar respostas em até 10 segundos.
  * **🔥 Sistema de Streak/Combo:** Multiplicador de pontos para acertos consecutivos.
  * **👨‍🏫 Modo Professor Integrado:** Interface direta no menu para cadastrar novas perguntas em tempo de execução.

---

## 🏗️ 2. Arquitetura do Sistema e Fluxo de Dados
*(Utilize este gráfico no telão para guiar a explicação técnica para a banca examinadora)*

```mermaid
flowchart LR
    %% Estilização do Diagrama
    classDef arquivo fill:#ffe3e3,stroke:#ff6b6b,stroke-width:2px;
    classDef memoria fill:#e3fafc,stroke:#1098ad,stroke-width:2px;
    classDef motor fill:#f3e8ff,stroke:#9333ea,stroke-width:2px;

    subgraph Armazenamento (.txt)
        A[📄 perguntas.txt <br> Bloco de 7 linhas]:::arquivo
        E[🏆 ranking.txt <br> Formato Nome;Pontos]:::arquivo
    end

    subgraph Execução em Memória
        B[🧠 RAM: malloc dinâmico <br> com cálculo de linhas / 7]:::memoria
        C{⚙️ Motor do Jogo em C <br> Menu Principal}:::memoria
    end

    subgraph Regras de Negócio de Nota Extra
        F[⏱️ Controle de Tempo: time.h]:::motor
        G[🔥 Combo Multiplicador ++]:::motor
        H[🎲 Recursão: embaralhar]:::motor
    end

    A -->|Leitura e parser| B
    B -->|Vetor de Structs| C
    C -->|Validações| F & G & H
    C -->|Grava Placar Top 10| E
    C -.->|Modo Professor: Append| A
