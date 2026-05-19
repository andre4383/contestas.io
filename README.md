# 🏆 Contestas.io
> **Apresentação do Projeto - Hackathon**

---

## 💡 1. O Insight Pedagógico (O Problema vs. A Solução)

* **O Desafio Comum:** Em sistemas tradicionais, mudar as perguntas de um jogo exige alterar o código-fonte e compilar o programa novamente.
* **A Nossa Solução:** **Separação total entre Dados e Lógica.** O professor pode adicionar, editar ou remover perguntas usando um arquivo de texto comum (`.txt`). O programa em C lê esses dados dinamicamente, sem precisar de nova recompilação!

---

## 🏗️ 2. Arquitetura do Sistema e Fluxo de Dados
*(Abra este gráfico na tela do GitHub para explicar a estrutura técnica para a banca)*

```mermaid
flowchart TD
    %% Estilos visuais para a apresentação
    classDef arquivo fill:#ffe3e3,stroke:#ff6b6b,stroke-width:2px;
    classDef codigo fill:#e3fafc,stroke:#1098ad,stroke-width:2px;
    classDef ator fill:#fff9db,stroke:#f59f00,stroke-width:2px;

    A[👨‍🏫 Professor / Usuário]:::ator
    B[📄 perguntas.txt]:::arquivo
    C[🧠 Memória RAM <br> Vetor Dinâmico com 'malloc']:::codigo
    D{⚙️ Motor do Jogo <br> Loop principal em C}:::codigo
    E[🏆 ranking.txt <br> Gravação do Top 10]:::arquivo

    %% Fluxo de Informação
    A -->|1. Interage com o Menu| D
    B -->|2. Leitura via 'fopen'| C
    C -->|3. Alimenta em tempo real| D
    D -->|4. Mistura com 'Recursão'| D
    D -->|5. Atualiza placar| E
    A -.->|Modo Professor: Edita direto| B
